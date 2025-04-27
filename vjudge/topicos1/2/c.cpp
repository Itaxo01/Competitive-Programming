#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 10000000000000037;
int n, k;
vector<int> pot;

int sum(int a, int b){
	return ((a%mod)+(b%mod))%mod;
}

int fast_mult(int a, int b){
	int res = 1;
	while(b){
		if(b & 1){
			res = sum(a, b);
		}
		a = sum(a, a);
		b >>=1;
	}
	return res;
}


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>k;
	pot.resize(k);
	int s = 1; pot[0] = s;
	for(int i = 1; i<k; i++){
		s = fast_mult(s, (n+1));
		pot[i] = s;
	}
	
	int hash_global = 0;
	int all_one_hash = 0;
	for(int i = 0; i<k; i++){
		all_one_hash = sum(all_one_hash, pot[i]);
	}
	unordered_map<int, int> m;
	
	vector<int> freq(k, 0);
	vector<int> freq_freq(n+1, 0);
	freq_freq[0] = k;

	int pos = 0;
	int maior = 0;
	int zeros = k;
	m[hash_global] = -1;
	

	for(int i = 0; i<n; i++){
		int a; cin>>a;
		freq_freq[freq[a-1]]--;
		freq[a-1]++;
		freq_freq[freq[a-1]]++;
		hash_global = sum(hash_global, pot[a-1]);
		
		if(freq_freq[pos] == 0){
			zeros = freq_freq[++pos];
			hash_global = ((hash_global-all_one_hash)%mod+mod)%mod;
		}

		if(m.find(hash_global) != m.end()){
			maior = max(maior, i-m[hash_global]);
		} else {
			m[hash_global] = i;
		}
	}
	cout<<maior<<endl;
	
}