#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = (int)(1e9+7);

void dfs(int v, int p, bool &res, vector<bool> &visited, vector<vector<int>> &adj, int &K) {
	if(visited[v]) {
		res = false;
		return;
	}
	else visited[v] = true;
	K++;
	for(int u: adj[v]){
		if(u != p) dfs(u, v, res, visited, adj, K);
	}
}

ll fast_pow(ll a, ll b){
	ll r = 1;
	while(b){
		if(b & 1) r = (r*a)%M;
		a = (a*a)%M;
		b>>=1;
	}
	return r;
}

ll fat(ll a, ll b){
	ll r = 1;
	for(ll i = a; i > b; i--){
		r = (r*i)%M;
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k; cin>>n>>k;
	
	vector<vector<int>> adj(n);
	for(int i = 0; i<k; i++){
		int a, b; cin>>a>>b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	bool res = true;
	for(auto &v: adj){
		if(v.size() >= 3) res = false;
	}
	
	// se houver algum componente ciclico não há resposta.
	ll c = 0;
	ll T = 0;
	vector<bool> visited(n, false);
	for(int i = 0; i<n; i++){
		if(visited[i]) continue;
		int K = 0;
		T++; // cada componente
		dfs(i, -1, res, visited, adj, K);
		if(K >= 2) {
			c++; // cada componente >= 2
		}
	}
	if(!res) cout<<-1<<endl;
	else {
		ll mult = (fast_pow(2, c) * fat(T, 1))%M; // cada componente de tamanho >=2 pode estar normal ou invertida.
		cout<<mult<<endl;
	}
}