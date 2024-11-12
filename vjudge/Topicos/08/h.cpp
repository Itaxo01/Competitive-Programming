#include <bits/stdc++.h>
using namespace std;
int parent[100005];
int tamanho[100005];


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
	int tt; cin>>tt;
	while(tt--){
		int a, b; cin>>a>>b;
		vector<pair<int, pair<int, int>>> edges(b);
		for(int i = 0; i<a; i++){
			parent[i] = -1;
			tamanho[i] = 1;
		}
		for(int i = 0; i<b; i++){
			int x, y, z; cin>>x>>y>>z;
			edges[i] = {z, {x-1, y-1}};
		}
		sort(edges.begin(), edges.end());

		vector<int> mst_edges;

		int mcost = 0;
		for(int i = 0; i<b; i++){
			auto front = edges[i];
			// cout<<find(front.second.first)<<" "<<find(front.second.second)<<endl;
			if(find(front.second.first) != find(front.second.second)){
				mcost += front.first;
				Union(front.second.first, front.second.second);
				mst_edges.push_back(i);
				// cout<<front.second.first<<" "<<front.second.second<<" "<<edges[i].first<<endl;
			}
		}

		int scost = INT_MAX;
		bitset<200> visitados;
		for(int j = 0; j<mst_edges.size(); j++){
			int scost_ = 0;
			for(int k = 0; k<a; k++){
				parent[k] = -1;
				tamanho[k] = 1;
			}
			visitados.reset();
			for(int i = 0; i<b; i++){
				if(i == mst_edges[j]) continue;
				auto front = edges[i];
				if(find(front.second.first) != find(front.second.second)){
					scost_ += front.first;
					visitados.set(front.second.first);
					visitados.set(front.second.second);
					Union(front.second.first, front.second.second);
				}
			}
			if(visitados.count() != a) continue;
			// cout<<scost_<<endl;
			if(scost_ >= mcost) scost = min(scost, scost_);
		}
		cout<<mcost<<" "<<scost<<endl;
	}
}