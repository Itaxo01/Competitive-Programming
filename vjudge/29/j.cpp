#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
vector<vector<int>> adj;

int main(){
	cin>>n>>m>>s>>t;
	adj.assign(n, vector<int>());
	for(int i = 0; i<m; i++){
		int u, v; cin>>u>>v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// vou ter o caminho mínimo com uma simples bfs
	// a ideia aqui é de que para eu ter um caminho com o custo D+1 ele terá que obrigatóriamente fazer parte em sua maioria do caminho principal. Se o caminho fosse algo do tipo s->a->b->c->t, um caminho válido teria que estar incluso entre algum dos vértices do caminho principal, como entre s->aux->a->b->c->t. 
	// dessa forma, para cada par de vértices A e B do caminho, eu preciso saber quantos vértices satisfazem essa propriedade, isto é, quantos vértices são compartilhados pelo vértice A e B.


}