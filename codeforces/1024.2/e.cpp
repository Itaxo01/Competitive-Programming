#include <bits/stdc++.h>
#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int calculate(vector<int> &v){
	unordered_map<int, int> m;
	int sum = 0;
	for(int i = 0; i<v.size(); i++){
		if(m.find(v[i]) != m.end()){
			sum += i - m[v[i]];
		}
		m[v[i]] = i;
	}
	return sum;
}

vector<int> v;
bool cmp(int a, int b){
	return v[a] < v[b];
}

void work(){
	int n; cin>>n;
	v.resize(n);
	map<int, int> m;
	vector<int> pos1(n/2);
	vector<int> pos2(n/2);
	vector<int> v_original(n);
	for(int i = 1; i<= n; i++){
		m[i]++;
	}
	for(int i = 0; i<n; i++){
		cin>>v[i];
		v_original[i] = v[i];
	}
	for(int i = 0; i<n/2; i++){
		pos1[i] = i;
		pos2[i] = i + n/2 + (n & 1);
	}
	// Vou tentar maximizar a quantidade de pares diferentes
	sort(pos1.rbegin(), pos1.rend(), cmp);
	sort(pos2.rbegin(), pos2.rend(), cmp);
	for(int i = 0; i < n/2; i++){
		int a = min(v[pos1[i]], v[pos2[i]]);
		auto it = m.upper_bound(a);
		if(it != m.begin()){
			--it;
			v[pos1[i]] = it->first; v[pos2[i]] = it->first;
			m.erase(it);
		}
	}
	if(n & 1){
		v[n/2] = v[0];
	}
	for(int i = 1; i<n-1; i++){
		if(v[i-1] == v[i] && v[i] == v[i+1]){
			if(v_original[i] > v[i]) v[i] = v_original[i];
		}
	}
	cout<<calculate(v)<<endl;
}

signed main(){
	fastio
	int tt; cin>>tt;
	while(tt--){
		work();
	}
}