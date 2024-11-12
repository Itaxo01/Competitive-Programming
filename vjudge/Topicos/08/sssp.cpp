#include <bits/stdc++.h>
using namespace std;

int bfs(int a, int b, int res, vector<vector<int>> &v){
	if(a == b) return 0;
	vector<bool> visitados(v.size(), false);
	queue<pair<int, int>> q;
	q.push({a, 0});
	while(!q.empty()){
		auto p = q.front();
		if(p.first == b) return p.second;
		q.pop();
		for(auto k: v[p.first]){
			if(!visitados[k]){
				visitados[k] = true;
				q.push({k, p.second+1});
			}
		}
	}
	return -1;
}

int main(){
	int a, b; cin>>a>>b;
	vector<vector<int>> adj(a);
	for(int i = 0; i<b; i++){
		int x, y; cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
}