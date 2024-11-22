#include <bits/stdc++.h>
// #define int long long
#define ii pair<int, int>
const int INF = 1e9;
using namespace std;

void floydwarshall(vector<vector<int>> &v, vector<vector<int>> &usado){
	for(int i = 0; i<v.size(); i++){
		for(int j = 0; j<v.size(); j++){
			for(int k = 0; k<v.size(); k++){
				if(v[j][k] > v[j][i] + v[i][k]){
					v[j][k] = v[j][i] + v[i][k];
					usado[j][k] = 0;
				}
			}
		}
	}
}

int dijkstra(int a, int b, vector<vector<int>> &v){
	vector<int> dist(v.size(), INF);
	dist[a] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({0, a});
	while(!pq.empty()){
		auto p = pq.top(); pq.pop();
		int d = p.first, u = p.second;
		if(d > dist[u]) continue;
		for(int i = 0; i<v.size(); i++){
			if(v[u][i] && dist[u]+v[u][i] < dist[i]){
				dist[i] = dist[u]+v[u][i];
				pq.push({dist[i], i});
			}
		}
	}
	return dist[b];
}

signed main(){
	int a, b; cin>>a>>b;
	vector<vector<int>> v(a, vector<int>(a, INF));
	vector<vector<int>> v2(a, vector<int>(a));
	vector<ii> order;
	for(int i = 0; i<b ; i++){
		int x, y, w; cin>>x>>y>>w;
		v[x-1][y-1] = w;
		v[y-1][x-1] = w;
		v2[x-1][y-1] = w;
		v2[y-1][x-1] = w;
		order.push_back({x-1, y-1});
	}
	vector<vector<int>> usado(a, vector<int>(a, 1));
	floydwarshall(v, usado);

	
	for(auto e: order){
		if(!usado[e.first][e.second]) cout<<v[e.first][e.second]<<endl;
		else {
			int e1 = e.first, e2 = e.second;
			int temp = v2[e1][e2];
			v2[e1][e2] = INF;
			v2[e2][e1] = INF;
			int d = dijkstra(e1, e2, v2);
			if(d >= INF) cout<<-1<<endl;
			else cout<<d<<endl;
			v2[e1][e2] = temp;
			v2[e2][e1] = temp;
		}
	}
}
