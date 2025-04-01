#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;


void dijsktra(vector<vector<pii>> &graph, vector<pair<int, bool>> &d, int p, int g){
	int a = graph.size();
	d.resize(a, {INT_MAX, false});
	d[p] = {0, false};
	d[g].second = true;
	
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, p});
	while(!pq.empty()){
		int u = pq.top().second; pq.pop();
		if(u == g) d[u].second = true;
		for(auto e: graph[u]){
			int v = e.second;
			int w = e.first;
			if(d[v].first > d[u].first + w){
				d[v].first = d[u].first+w;
				d[v].second = d[u].second;
				pq.push({d[v].first, v});
			} else if(d[v].first == d[u].first+w){
				if(d[v].second && !d[u].second) d[v].second = false;
			}
		}
	}
	bool first = true;
	for(int i = 0; i<a; i++){
		//cout<<"Vertice "<<i+1<<": ";
		//cout<<"custo "<<d[i].first<<", passa por g: "<<d[i].second<<endl;
		if(d[i].first == 2*d[g].first && d[i].second){
			if(!first) cout<<" ";
			first = false;
			cout<<i+1;
		}
	} 
	if(first) cout<<"*";
	cout<<endl;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b; cin>>a>>b;
	vector<vector<pii>> v(a);
	int p, g; cin>>p>>g;
	p--; g--;
	for(int i = 0; i<b; i++){
		int u, v1, w; cin>>u>>v1>>w;
		u--; v1--;
		v[u].push_back({w, v1});
		v[v1].push_back({w, u});
	}
	vector<pair<int, bool>> d;
	dijsktra(v, d, p, g);

}