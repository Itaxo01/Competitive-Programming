#include<bits/stdc++.h>
#define ll long long
 
const ll mod = 1e9+7;
using namespace std;
 
 
vector<int> adj[1000005];
 
int factor[1000005];
int visited[1000005];
 
bitset<1000005> prime;
bitset<1000005> prats;
 
ll potencias[1000005];
ll memo[1000000];
 
 
int dfs(int u){
	int total = 0;
 
	if (visited[u] == 0 && prats.test(u)) {
		total++;
	}
	
	visited[u] = 1;
 
	for (int v: adj[u]) {
		if (!visited[v]) {
			total += dfs(v);
		}
	}
 
	return total;
}
 
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
 
	memset(memo, -1, sizeof(memo));
	for (int i = 0; i <= 1000000; i++) {
		factor[i] = i;
	} 
 
	prime.set();
	for (int i = 2; i <= 1000; i++) {
		if (prime.test(i)) {			
			for (ll j = i; j <= 1000000; j+=i) {
				prime.reset(j);
				factor[j] = i;
			}
		}
	}
 
	potencias[0] = 1;
	for (int i = 1; i < 100001; i++) {
		potencias[i] = (2 * potencias[i-1]) % mod;
	}
 
	prats.reset();
	int nPratos; cin>>nPratos;
	for (int i = 0; i < nPratos; i++) {
		int prato; cin>>prato;
		int currentFactor = prato;
		prats.set(prato);
 
		while (currentFactor > 1) {
			adj[factor[currentFactor]].push_back(prato);
			currentFactor /= factor[currentFactor];
		}
	}
 
	int nAllergies; cin>>nAllergies;
	for (int i = 0; i < nAllergies; i++) {
		int allergy; cin>>allergy;
 
		set<ll> factors;
		ll currentFactor = allergy;
		ll total = 0;
 
		while (currentFactor > 1) {
			factors.insert(factor[currentFactor]);
			currentFactor /= factor[currentFactor];
		}
 
		ll reducedAllergy = 1;
		for (ll f: factors) {
			reducedAllergy *= f;
		}
 
		if (memo[reducedAllergy] == -1) {
			memset(visited, 0, sizeof(visited));
			for (ll f: factors) {
				total += dfs(f);
			}
 
			memo[reducedAllergy] = potencias[nPratos-total]; 
		}
 
		cout<<memo[reducedAllergy]<<endl;
	} 
 
	return 0;
}