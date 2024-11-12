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

double dist(double x1, double y1, double x2, double y2){
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void storeEdges(vector<pair<double, pair<int, int>>> &edges, int a){
	vector<pair<double, double>> points;
	for(int i = 0; i<a; i++){
		double x, y; cin>>x>>y;
		points.push_back({x, y});
	}
	for(int i = 0; i<a; i++){
		for(int j = i+1; j<a; j++){
			double d = dist(points[i].first, points[i].second, points[j].first, points[j].second);
			edges.push_back({d, {i, j}});
		}
	}
}

int main(){
	int tt; cin>>tt;
	while(tt--){
		int a, b; cin>>a>>b;
		vector<pair<double, pair<int, int>>> edges;
		for(int i = 0; i<250005; i++){
			parent[i] = -1;
			tamanho[i] = 1;
		}

		storeEdges(edges, b);
		sort(edges.begin(), edges.end());
		
		double maior = 0;
		int count = 0;
		for(int i = 0; i<edges.size(); i++){
			auto front = edges[i];
			if(find(front.second.first) != find(front.second.second)){
				maior = max(maior, front.first);
				Union(front.second.first, front.second.second);
				count++;
				if(b-count == a){
					break;
				}
			}
		}
		printf("%.2f\n", maior);
	}
}