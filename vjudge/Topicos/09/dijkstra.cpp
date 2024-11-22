#include <bits/stdc++.h>
#define ii pair<int, int>
const int INF = 0x7FFFFFFF;
using namespace std;

void dijkstra(int a, int b, vector<vector<ii>> &v){
	vector<int> dist(v.size(), INF);
	dist[a] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({0, a});
	while(!pq.empty()){
		auto p = pq.top(); pq.pop();
		int d = p.first, u = p.second;
		if(d > dist[u]) continue;
		for(auto e: v[p.second]){
			if(dist[u]+e.second < dist[e.first]){
				dist[e.first] = dist[u]+e.second;
				pq.push({dist[e.first], e.first});
			}
		}
	}
}

int main(){
	int a, b; cin>>a>>b;
	vector<vector<ii>> v(a);
	for(int i = 0; i<b ; i++){
		int x, y, w; cin>>x>>y>>w;
		v[x-1].push_back({y-1, w});
		v[y-1].push_back({x-1, w});
	}
}