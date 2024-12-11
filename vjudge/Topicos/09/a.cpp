#include <bits/stdc++.h>
#define INF 1e9
#define ii pair<int, int>

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
	return dist[b];
}

int main(){
	while(true){
		int a; cin>>a;
		if(!a) break;
		string s_in, s_fim; cin>>s_in>>s_fim;
		map<string, int> palavras;

		map<string, vector<string>> m1; // Palavras de cada lingua 1
		map<string, vector<string>> m2; // Palavras de cada lingua 2

		vector<vector<ii>> graph(a+2);
		for(int i = 0; i<a; i++){
			string s1, s2, s3; cin>>s1>>s2>>s3;
			int b = palavras[s3] = palavras.size()+1;
			for(string e: m1[s2]){
				if(e[0] == s3[0]) continue;
				int e1 = palavras[e];
				graph[e1].push_back({b, s3.size()});
				graph[b].push_back({e1, e.size()});
			}
			for(string e: m2[s1]){
				if(e[0] == s3[0]) continue;
				int e1 = palavras[e];
				graph[e1].push_back({b, s3.size()});
				graph[b].push_back({e1, e.size()});
			}
			for(string e: m2[s2]){
				if(e[0] == s3[0]) continue;
				int e1 = palavras[e];
				graph[e1].push_back({b, s3.size()});
				graph[b].push_back({e1, e.size()});
			}
			for(string e: m1[s1]){
				if(e[0] == s3[0]) continue;
				int e1 = palavras[e];
				graph[e1].push_back({b, s3.size()});
				graph[b].push_back({e1, e.size()});
			}
			m1[s1].push_back(s3);
			m2[s2].push_back(s3);
		}
		for(string e: m1[s_in])
			graph[0].push_back({palavras[e], e.size()});
		for(string e: m2[s_in])
			graph[0].push_back({palavras[e], e.size()});
		for(string e: m1[s_fim])
			graph[palavras[e]].push_back({a+1, 0});
		for(string e: m2[s_fim])
			graph[palavras[e]].push_back({a+1, 0});
		
		// for(int i = 0; i<graph.size(); i++){
		// 	cout<<"Vertice "<<i<<endl;;
		// 	for(auto e: graph[i]){
		// 		cout<<e.first<<" "<<e.second<<endl;
		// 	}
		// }
		int res = dijkstra(0, a+1, graph);
		if(res >= INF) cout<<"impossivel\n";
		else cout<<res<<"\n";
	}
}