#include <bits/stdc++.h>
using namespace std;

void dfs(vector<bool> &visitados, vector<vector<int>> &adj, stack<int> &s, int i){
	visitados[i] = true;
	for(auto e: adj[i]){
		if(!visitados[e]){
			dfs(visitados, adj, s, e);
		}
	}
	s.push(i);
}

void dfs2(vector<bool> &visitados, vector<vector<int>> &adj,
		  unordered_set<int> &s, int i, int g, int parent[]){
	visitados[i] = true;
	for(auto e: adj[i]){
		if(!visitados[e]){
			dfs2(visitados, adj, s, e, g, parent);
		}
	}
	s.insert(i);
	parent[i] = g;
}

void condense(int i, vector<vector<int>> &adj, vector<vector<int>> &n_adj,
				vector<bool> &visited, int parents[]){
	visited[i] = true;
	for(int e: adj[i]){
		if(parents[e]==parents[i]) continue;
		else n_adj[parents[i]].push_back(parents[e]);
		if(!visited[e]) condense(e, adj, n_adj, visited, parents);
	}
}	

int main(){
	int tt; cin>>tt;
	while(tt--){
		int a, b; cin>>a>>b;
		vector<vector<int>> s_d(a);
		vector<vector<int>> transpose(a);
		for(int i = 0; i<b; i++){
			int c, d; cin>>c>>d;
			s_d[c-1].push_back(d-1); 
			transpose[d-1].push_back(c-1); 
		}

		stack<int> s;
		vector<bool> visitados(a, false);
		for(int i = 0; i<a; i++){
			if(!visitados[i]){
				dfs(visitados, s_d, s, i);
			}
		}
		
		visitados.assign(a, false);

		int g = 0;
		int parent[a] = {0};
		vector<unordered_set<int>> sccs;
		while(!s.empty()){
			int i = s.top();
			s.pop();
			if(!visitados[i]){
				unordered_set<int> scc;
				dfs2(visitados, transpose, scc, i, g, parent);
				sccs.push_back(scc);
				g++;
			}
		}
		vector<vector<int>> n_adj(sccs.size());
		visitados.assign(a, false);
		
		for(int i = 0; i<a; i++){
			if(!visitados[i]){
				condense(i, s_d, n_adj, visitados, parent);
			}
		}
		int pesos[n_adj.size()] = {0};
		for(int i = 0; i<n_adj.size(); i++){
			for(int e: n_adj[i]){
				pesos[e]++;
			}
		}
		int count = 0;
		for(int i = 0; i<n_adj.size(); i++){
			if(pesos[i] == 0){
				count++;
			}
		}
		cout<<count<<endl;
	}
}