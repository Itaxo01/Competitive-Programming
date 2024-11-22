#include <bits/stdc++.h>
#define ii pair<int, int>
const int INF = 0x7FFFFFFF;
using namespace std;

int dijkstra(int a, int b, vector<vector<ii>> &v){
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
	int count = 0;
	for(int e: dist){
		if(e <= b) count++;
	}
	return count;
}

int main(){
	int tt; cin>>tt;
	bool first = true;
	while(tt--){
		int a, b, c, d; cin>>a>>b>>c>>d;
		vector<vector<ii>> v(a);
		if(!first) cout<<endl;
		first = false;
		for(int i = 0; i<d ; i++){
			int x, y, w; cin>>x>>y>>w;
			v[y-1].push_back({x-1, w});
		}
		cout<<dijkstra(b-1, c, v)<<endl;
	}
}