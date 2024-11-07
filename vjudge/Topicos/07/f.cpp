#include <bits/stdc++.h>
using namespace std;
int parent[10005];
int ranks[10005];

void dfs(int a, int p, int t, vector<vector<int>> &adj, vector<bool> &visitados,
		vector<int> &ord, vector<int> &low, vector<pair<int, int>> &pontes){
	t++;
	visitados[a] = true;
	low[a] = ord[a] = t;
	for(int e: adj[a]){	
		if(!visitados[e]){
			dfs(e, a, t, adj, visitados, ord, low, pontes);
			low[a] = min(low[a], low[e]);
			if(low[e]>ord[a]){
				pontes.push_back({a, e});
			}
		} else if(e != p){
			low[a] = min(low[a], ord[e]);
		}
	}	
}


int find(int a){
	if(parent[a] == -1) return a;
	return parent[a] = find(parent[a]);
}

void join(int a, int b){
	int i = find(a);
	int j = find(b);
	if(i == j) return;
	int ri = ranks[i];
	int rj = ranks[j];
	if(ri>rj)
		parent[j] = i;
	else{
		parent[i] = j;
		if(ri == rj) ranks[j]++;
	}
}

int main(){
	int a, b, c;
	while(cin>>a>>b>>c){
		if(!a && !b && !c) break;
		vector<vector<int>> adj(a);
		for(int i = 0; i<b; i++){
			int u, v; cin>>u>>v;
			adj[u-1].push_back(v-1);
			adj[v-1].push_back(u-1);
		}
		vector<bool> visitados(a, false);
		vector<int> ord(a, -1), low(a, -1);
		int t = 0;
		vector<pair<int, int>> pontes;

		for(int i = 0; i<a; i++){
			if(!visitados[i]){
				dfs(i, -1, t, adj, visitados, ord, low, pontes);
			}
		}
		memset(parent, -1, sizeof(parent));
		memset(ranks, 0, sizeof(ranks));
		for(auto e: pontes){
			join(e.first, e.second);
		}

		for(int i = 0; i<c; i++){
			int qu, qv; cin>>qu>>qv;
			if(find(qu-1) == find(qv-1))
				cout<<"Y\n";
			else
				cout<<"N\n";
		}
		cout<<"-\n";
	}
}