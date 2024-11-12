#include <bits/stdc++.h>
using namespace std;
int parent[250005];
int tamanho[250005];

void dfs(int a, int b, int res, vector<vector<pair<int, int>>> &v, vector<bool> &visitados){
	visitados[a] = true;
	// if(visitados[b]) return;
	if(a == b){
		cout<<res<<endl;
		return;
	}
	for(auto e: v[a]){
		if(!visitados[e.first]){
			res = max(res, e.second);
			dfs(e.first, b, res, v, visitados);
		}
	}

}

int find(int i){
	if(parent[i] == -1) return i;
	return parent[i] = find(parent[i]);
}

void Union(int a, int b){
	int x = find(a);
	int y = find(b);
	if(x != y){
		if(tamanho[x] < tamanho[y]){
			parent[x] = y;
			tamanho[y] += tamanho[x];
		}
		else{
			parent[y] = x;
			tamanho[x] += tamanho[y];
		}
	}
}

int main(){
	int count = 1;
	while (true) {
		int a, b, c; cin>>a>>b>>c;
		if(!a && !b && !c) break;
		if(count != 1) cout<<endl;
		vector<pair<int, pair<int, int>>> edges;
		for(int i = 0; i<250005; i++){
			parent[i] = -1;
			tamanho[i] = 1;
		}

		for(int i = 0; i<b; i++){
			int x, y, z; cin>>x>>y>>z;
			edges.push_back({z, {x-1, y-1}});
		}
		
		sort(edges.begin(), edges.end());
		vector<pair<int, int>> queries(c);
		map<pair<int, int>, int> m;
		for(int i = 0; i<c; i++){
			int x, y; cin>>x>>y;
			queries[i] = {x-1, y-1};
		}

		vector<vector<pair<int, int>>> adj(a);
		for(int i = 0; i<edges.size(); i++){
			auto front1 = edges[i].second.first;
			auto front2 = edges[i].second.second;

			if(find(front1) != find(front2)){
				Union(front1, front2);
				adj[front1].push_back({front2, edges[i].first});
				adj[front2].push_back({front1, edges[i].first});
				// cout<<front1<<" "<<front2<<" "<<edges[i].first<<endl;
			}
		}

		printf("Case #%d\n", count++);

		vector<bool> visitados(a, false);
		for(auto e: queries){
			if(find(e.first) != find(e.second)) cout<<"no path"<<endl;
			else{
				visitados.assign(a, false);
				dfs(e.first, e.second, 0, adj, visitados);
			}
				
		}		
	}
}