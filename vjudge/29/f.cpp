#include <bits/stdc++.h>
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
using namespace std;

int N, M, K;
vector<vector<pi>> adj;

ll dijkstra(int a, int b){
	vector<ll> dist(N+K, LLONG_MAX);
	dist[a] = 0;
	priority_queue<pl, vector<pl>, greater<pl>> pq;
	pq.push(make_pair(0, a));

	while(!pq.empty()){
		auto [w1, v] = pq.top(); pq.pop();

		for(auto [u, w2]: adj[v]){
			if(dist[u] > w1+w2){
				dist[u] = w1+w2;
				pq.push(make_pair(dist[u], u));
			}
		}
	}
	return dist[b];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>M>>K;
	adj.assign(N+K, vector<pi>());

	for(int i = 0; i<M; i++){
		int u, v, w; cin>>u>>v>>w;
		u--, v--;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}

	// da para pensar nos tp's como vértices adicionais.
	// um vértice v tem custo w para ir para N+u, e N+u tem custo 0 para ir para v.
	for(int v = 0; v<N; v++){
		int t; cin>>t;
		for(int j = 0; j<t; j++){
			int u, w; cin>>u>>w;
			u--;
			adj[N+u].push_back(make_pair(v, 0));
			adj[v].push_back(make_pair(N+u, w));
		}
	}

	cout<<dijkstra(0, N-1)<<endl;

}