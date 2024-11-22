#include <bits/stdc++.h>
#define ii pair<int, int>
#define ici pair<pair<int, char>, int>
#define INF 1e9
using namespace std;

int dijkstra(int a, int b, vector<vector<vector<pair<int, char>>>> &v){
	vector<pair<int, char>> dist(v.size(), pair<int, char>(INF, '.'));
	dist[a].first = 0;
	priority_queue<ici, vector<ici>, greater<ici>> pq;
	pq.push({dist[a], a});
	while(!pq.empty()){
		auto p = pq.top(); pq.pop();
		int d = p.first.first, u = p.second;
		if(d > dist[u].first) continue;
		for(int i = 0; i<v[u].size(); i++){
			for(auto e: v[u][i]){
				if (dist[u].second == e.second) continue;
				if(dist[u].first+e.first < dist[i].first){
					dist[i].first = dist[u].first+e.first;
					dist[i].second = e.second;
					pq.push({dist[i], i});
				}
			}
		}
	}
	return dist[b].first;
}

int main(){
	while(true){
		int a; cin>>a;
		if(!a) break;
		map<string, int> m;
		string s1, s2; cin>>s1>>s2;
		m[s1] = m.size();
		m[s2] = m.size();
		vector<vector<string>> input(a);
		for(int i = 0; i<a; i++){
			string s3, s4, s5; cin>>s3>>s4>>s5;
			input[i] = {s3, s4, s5};
			if(m.find(s3) == m.end()) m[s3] = m.size();
			if(m.find(s4) == m.end()) m[s4] = m.size();
		}
		int V = m.size();
		vector<vector<vector<pair<int, char>>>> v(V, vector<vector<pair<int, char>>>(V));
		for(int i = 0; i<a; i++){
			string s3 = input[i][0], s4 = input[i][1], s5 = input[i][2];
			v[m[s3]][m[s4]].push_back({s5.size(), s5[0]});
			v[m[s4]][m[s3]].push_back({s5.size(), s5[0]});
		}
		
		int ans = dijkstra(m[s1], m[s2], v);
		if(ans >= INF) cout<<"impossivel"<<endl;
		else cout<<ans<<endl;	
	}
}