#include <bits/stdc++.h>
#define ii pair<int, int>
#define INF 1000000000
using namespace std;

bool ncycle(int a, vector<vector<ii>> &v){ // check if there is a a negative cycle
	vector<int> dist(v.size(), INF);
	dist[a] = 0;
	for(int i = 0; i<v.size()-1; i++){
		for(int u = 0; u<v.size(); u++)
			for(int j = 0; j<v[u].size(); j++){
				ii aux = v[u][j];
				dist[aux.first] = min(dist[aux.first], dist[u] + aux.second);
		}
	}

	for(int i = 0; i<v.size(); i++){
		for(int j = 0; j<v[i].size(); j++){
			ii aux = v[i][j];
			if(dist[aux.first] > dist[i]+aux.second){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int tt; cin>>tt; while(tt--){
		int a, b; cin>>a>>b;
		vector<vector<ii>> v(a);
		for(int i = 0; i<b; i++){
			int x, y, w; cin>>x>>y>>w;
			v[x].push_back({y, w});
		}
		if(ncycle(0, v)) cout<<"possible";
		else cout<<"not possible";
		cout<<endl;
	}

}