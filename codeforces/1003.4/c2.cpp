#include <bits/stdc++.h>
#define int long long
#define INF INT_MAX
using namespace std;

void work(){
	int n, m; cin>>n>>m;
	vector<int> v1(n), v2(m);
	for(int i = 0; i<n; i++){
		cin>>v1[i];
	}for(int i = 0; i<m; i++){
		cin>>v2[i];
	}
	sort(v2.begin(), v2.end());
	// Sempre tentar diminuir o máximo possível o número, contanto que não
	// fique menor que o anterior
	if(v1[0] > (v2[0] - v1[0])) v1[0] = v2[0]-v1[0];
	for(int i = 1; i<n; i++){
		// para v1[i], o menor número que ele pode assumir é v1[i-1], dessa forma, precisa achar
		// o menor valor em v2 tal que v2[j] - v1[i] >= v1[i-1], o menor valor tal que v2[j] >= v1[i-1]+v1[i];
		// Faz-se isso pra todos e depois verifica-se a ordenação.

		auto it = lower_bound(v2.begin(), v2.end(), v1[i-1]+v1[i]);
		int d = distance(v2.begin(), it);
		if(d < m){
			int val = *it;
			v1[i] = min(v1[i] < v1[i-1] ? INF : v1[i], val-v1[i] < v1[i-1] ? INF : val-v1[i]);
		}
	}
	// cout<<v1[0];
	for(int i = 1; i<n; i++){
		// cout<<" "<<v1[i];
		if(v1[i-1] > v1[i]){
			cout<<"NO"<<endl;
			return;
		}
	} // cout<<endl;
	cout<<"YES"<<endl;
}


signed main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int tt; cin>>tt;
	while(tt--){
		work();
	}
}