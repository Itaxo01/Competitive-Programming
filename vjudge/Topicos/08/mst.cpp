#include <bits/stdc++.h>
using namespace std;
int parent[100005];
int tamanho[100005];


int find(int i){
	if(parent[i] == -1) return parent[i] = i;
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
	int a, b; cin>>a>>b;
	vector<pair<int, pair<int, int>>> edges(b);
	for(int i = 0; i<a; i++){
		parent[i] = -1;
		tamanho[i] = 1;
	}
	for(int i = 0; i<b; i++){
		int x, y, z; cin>>x>>y>>z;
		edges[i] = {z, {x, y}};
	}
	sort(edges.begin(), edges.end());
	int cost = 0;
	for(int i = 0; i<b; i++){
		auto front = edges[i];
		if(find(front.second.first) != find(front.second.second)){
			cost += front.first;
			Union(front.second.first, front.second.second);
		}
	}
	cout<<cost<<endl;
}