#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m; cin>>n>>m;
	vector<vector<int>> adj(n);
	for(int i =0; i<m; i++){
		int u, v; cin>>u>>v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<bool> res(n, true);
	res[n-1] = true;
	vector<bool> visited(n, false);
	visited[n-1] = true;

	stack<int> s; s.push(n-2);
	visited[n-2] = true;
	while(!s.empty()){
		int p = s.top(); s.pop();
		res[p] = false;
		for(int e: adj[p]){
			if(!visited[e]){
				visited[e] = true;
				s.push(e);
			}
		}
	}
	for(auto e: res){
		if(e) cout<<"A";
		else cout<<"B";
	} cout<<endl;
}