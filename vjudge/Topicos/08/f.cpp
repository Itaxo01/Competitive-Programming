#include <bits/stdc++.h>
using namespace std;
int parent[250005];
int tamanho[250005];


int find(int i){
	if(parent[i] == -1) return i;
	return find(parent[i]);
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
	int a, b, c; cin>>a>>b>>c;
	vector<pair<int, pair<int, int>>> edges;
	for(int i = 0; i<250005; i++){
		parent[i] = -1;
		tamanho[i] = 1;
	}

	for(int i = 0; i<b; i++){
		int x, y, z; cin>>x>>y>>z;
		edges.push_back({z, {x, y}});
	}
	
	sort(edges.begin(), edges.end());
	
	vector<vector<pair<int, int>>> adj;
	for(int i = 0; i<edges.size(); i++){
		auto front = edges[i];
		if(find(front.second.first) != find(front.second.second)){
			Union(front.second.first, front.second.second);
			adj[front.second.first].push_back({front.second.second, front.first});
			adj[front.second.second].push_back({front.second.first, front.first});
		}
	}

	for(int i = 0; i<c; i++){
		int x, y; cin>>x>>y;
		if(find(x)!=find(y)) cout<<"no path"<<endl;
		else{

		}
	}
}