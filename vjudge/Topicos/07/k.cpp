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

void dfs2(vector<bool> &visitados, vector<vector<int>> &adj, unordered_set<int> &s, int i){
	visitados[i] = true;
	for(auto e: adj[i]){
		if(!visitados[e]){
			dfs2(visitados, adj, s, e);
		}
	}
	s.insert(i);
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

		vector<unordered_set<int>> sccs;
		while(!s.empty()){
			int i = s.top();
			s.pop();
			if(!visitados[i]){
				unordered_set<int> scc;
				dfs2(visitados, transpose, scc, i);
				sccs.push_back(scc);
			}
		}
		visitados.assign(a, false);
		vector<vector<int>> final_graph(sccs.size()+1);
		for(int i = 0; i<sccs.size(); i++){
			for(int e: sccs[i]){
				for(int k: s_d[e]){
					if(!visitados[k]){
						visitados[k] = true;
						if(sccs[i].find(k) == sccs[i].end()){
							final_graph[i+1].push_back(i);
						}
					}
				}
			}
		}
		visitados.assign(a, false);
		int count = 0;
		for(int i = 0; i<final_graph.size(); i++){
			if(!visitados[i]){
				stack<int> s;
			}
		}
	}
}