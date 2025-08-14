#pragma optimize ("02")
#include <bits/stdc++.h>
// #define int long long
#define ll long long
#define all(v) v.begin(), v.end()
using namespace std;
using namespace chrono;

vector<int> dsu_tree(600005);
ll peso[600005];
vector<int> adj[600005];
ll folhas[600005];

vector<pair<int, int>> edges, new_edges;

int n, m;

bool cmp(pair<int, int> &a, pair<int, int> &b){
	// auto [a1, a2] = a;
	// auto [b1, b2] = b;
	// ll A = max(peso[a1], peso[a2]), B = max(peso[b1], peso[b2]);
	return max(peso[a.first], peso[a.second]) < max(peso[b.first], peso[b.second]);
	// return A < B;
}

struct DSU {
  vector<int> parent, size;
  DSU(int n) {
    parent.resize(n);
    size.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }
 
  int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
  }
  void join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (size[a] < size[b]) swap(a, b);
    parent[b] = a;
    size[a] += size[b];
  }
};
 
void MST(){
	// auto t3 = high_resolution_clock::now();
	sort(edges.begin(), edges.end(), cmp);
	// auto t4 = high_resolution_clock::now();
	// cerr << "Sorting: "<<duration_cast<milliseconds>(t4-t3).count()<<" ms\n";
  DSU dsu(n);

  for(int i = 0; i<m; i++){
	 auto [a, b] = edges[i];
	 if(dsu.find(a) != dsu.find(b)){
		dsu.join(a, b);
		new_edges.push_back(edges[i]);
	 }
  }
  m = new_edges.size();
//   edges = new_edges;
}


int getRoot(int u){
	if(u == dsu_tree[u]) return u;
	return dsu_tree[u] = getRoot(dsu_tree[u]);
}

void addEdge(int u, int v){
	u = getRoot(u), v = getRoot(v);
	
	dsu_tree[n] = n;
	dsu_tree[u] = dsu_tree[v] = n;
	peso[n] = max(peso[u], peso[v]);

	adj[n].push_back(u);
	if(u != v) adj[n].push_back(v);

	++n;
}

void build(){
	for(int i = 0; i<n; i++) dsu_tree[i] = i;
	
	for(int i = 0; i<m; i++) {
		auto [u, v] = new_edges[i];
		addEdge(u, v);

	}
}

int N;
vector<ll> res;

void dfs2_iterative(int start){
	stack<tuple<int, ll, int, ll>> s;
	s.push({start, 0LL, -1, 0LL});
	
	while(!s.empty()){
		auto [v, w, p, pw] = s.top(); s.pop();
		
		if(v < N) {
			if(peso[v] != peso[p]) {
				pw = pw - peso[p] + peso[v];
			}
			res[v] = pw; 
			continue;
		}	
		
		ll k = peso[v]*folhas[v];
		if(p != -1) k+=w;
		
		for(int i = adj[v].size()-1; i>=0; i--){
			int u = adj[v][i];
			if(u != p){
				ll nw = w+(folhas[v]-folhas[u])*peso[v];
				s.push({u, nw, v, k});
			}
		}
	}
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	N = n; res.resize(n);

	// auto t1 = high_resolution_clock::now();
	
	memset(folhas, 0LL, sizeof(folhas));
	memset(peso, 0LL, sizeof(peso));
	for(int i = 0; i<n; i++){
		cin>>peso[i];
	}
	edges.resize(m);
	for(int i = 0; i<m; i++){
		int a, b; cin>>a>>b; a--, b--;
		edges[i] = make_pair(a, b);
	}

	// auto t2 = high_resolution_clock::now();
	// cerr << "Loading: "<<duration_cast<milliseconds>(t2-t1).count()<<" ms\n";

	
	// auto t3 = high_resolution_clock::now();
	MST();
	// auto t4 = high_resolution_clock::now();
	// cerr << "MST: "<<duration_cast<milliseconds>(t4-t3).count()<<" ms\n";
	// t3 = high_resolution_clock::now();
	build();
	// t4 = high_resolution_clock::now();
	// cerr << "Building: "<<duration_cast<milliseconds>(t4-t3).count()<<" ms\n";
	
	
	// t3 = high_resolution_clock::now();
	stack<int> s1, s2;
	s1.push(n-1);
	
	while(!s1.empty()){
		int v = s1.top(); s1.pop();
		s2.push(v);
		for(int u : adj[v]) s1.push(u); 
	}
	// Arvore invertida
	while(!s2.empty()){
		int v = s2.top(); s2.pop();
		if(adj[v].empty()) folhas[v] = 1;
		else{
			folhas[v] = 0;
			for(int u: adj[v]) folhas[v] += folhas[u];
		}
	}
	// t4 = high_resolution_clock::now();
	// cerr << "Leafs: "<<duration_cast<milliseconds>(t4-t3).count()<<" ms\n";
	
	// auto t5 = high_resolution_clock::now();
	
	dfs2_iterative(n-1); // Aparentemente melhor não usar recursão aqui
	
	for(int i = 0; i<N; ++i){
		if(i) cout<<" ";
		cout<<res[i];
	}
	 cout<<endl;
	
	// auto t6 = high_resolution_clock::now();
	// cerr << "Answer: "<<duration_cast<milliseconds>(t6-t5).count()<<" ms\n";
}