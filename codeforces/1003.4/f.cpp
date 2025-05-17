#include <bits/stdc++.h>
#define int long long
using namespace std;

// LCA by binary_lifting
vector<int> st, en;
vector<vector<int>> adj, up; // up is the "ancestors" vector but up[i][j] is the 2^j ancestor of i.
int n, tmp, max_it;

vector<int> values;
void dfs(int v, int p){
	st[v] = ++tmp;	
	up[v][0] = p;
	for(int i = 1; i<= max_it; i++){
		up[v][i] = up[up[v][i-1]][i-1];
	}
	for(int e: adj[v]){
		if(e != p){
			dfs(e, v);
		}
	}
	en[v] = ++tmp;
}
bool is_ancestor(int u, int v){
	return st[u] <= st[v] && en[u] >= en[v];
}

int lca(int u, int v){
	if(is_ancestor(u, v)) return u;
	if(is_ancestor(v, u)) return v;
	for(int i = max_it; i>=0; --i){
		if(!is_ancestor(up[u][i], v)) u = up[u][i];
	}
	return up[u][0];
}

void pre_compute_lca(int root){
	st.resize(n); en.resize(n);
	tmp = 0;
	max_it = ceil(log2(n));
	up.assign(n, vector<int>(max_it+1));
	dfs(root, root);
}

void work(){
	int n; cin>>n;
	values.resize(n);

	for(int i = 0; i<n; i++){
		cin>>values[i];
	}
	for(int i = 0; i<n-1; i++){
		int u, v; cin>>u>>v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	

}


signed main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int tt; cin>>tt;
	while(tt--){
		work();
	}
}