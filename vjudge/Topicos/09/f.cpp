#include <bits/stdc++.h>
using namespace std;
int parent[10005];
int tamanho[10005];


int find(int i){
	if(parent[i] == -1) return parent[i] = i;
	if(parent[i] == i) return i;
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

int distsq(pair<int, int> &a, pair<int, int>&b){
	return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}


void solve(vector<vector<pair<int, int>>> &v, int a, int b, vector<bool> visited,
				int &min_c, int c){
	visited[a] = true;
	if(a == b) min_c = min(min_c, c);
	for(auto e: v[a]){
		if(!visited[e.first]){
			solve(v, e.first, b, visited, min_c, max(c, e.second));
		}
	}
}

int main(){
	int c = 1;
	while(true){
		int a; cin>>a;
		if(!a) break;

		vector<pair<int, int>> p(a);
		for(int i = 0; i<a; i++){
			cin>>p[i].first>>p[i].second;
			parent[i] = -1;
			tamanho[i] = 1;
		}
		
		vector<pair<int, pair<int, int>>> edges;
		for(int i = 0; i<a; i++){
			for(int j = 0; j<a; j++){
				if(i==j) continue;
				int d = distsq(p[i], p[j]);
				edges.push_back({d, {i, j}});
			}
		}
		sort(edges.begin(), edges.end());
		vector<vector<pair<int, int>>> v_(a);
		for(int i = 0; i<edges.size(); i++){
			auto front = edges[i];
			if(find(front.second.first) != find(front.second.second)){
				Union(front.second.first, front.second.second);
				v_[front.second.first].push_back( {front.second.second, front.first});
				v_[front.second.second].push_back({front.second.first, front.first});
			}
		}
		int min_c = INT_MAX;
		vector<bool> visited(a, false);
		solve(v_, 0, 1, visited, min_c, 0);
		
		printf("Scenario #%d\nFrog Distance = %.3f\n\n", c++, sqrt(min_c));
	}
	
}