#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 1000000000
using namespace std;

// Isso printa facil qualquer estrutura nativa do c++
// só chamar debug(x). O ifndef faz ele não dar erro mesmo se deixado na hora
// de submeter no codeforces, não tenho certeza se funciona da mesma forma em outras
// plataformas.
/******** Debug Code *******/
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename A>
void __print(const A &x);
template <typename A, typename B>
void __print(const pair<A, B> &p);
template <typename... A>
void __print(const tuple<A...> &t);
template <typename T>
void __print(stack<T> s);
template <typename T>
void __print(queue<T> q);
template <typename T, typename... U>
void __print(priority_queue<T, U...> q);
template <typename A>
void __print(const A &x) {
    bool first = true;
    cerr << '{';
    for (const auto &i : x) {
        cerr << (first ? "" : ","), __print(i);
        first = false;
    }
    cerr << '}';
}
template <typename A, typename B>
void __print(const pair<A, B> &p) {
    cerr << '(';
    __print(p.first);
    cerr << ',';
    __print(p.second);
    cerr << ')';
}
template <typename... A>
void __print(const tuple<A...> &t) {
    bool first = true;
    cerr << '(';
    apply([&first](const auto &...args) { ((cerr << (first ? "" : ","), __print(args), first = false), ...); }, t);
    cerr << ')';
}
template <typename T>
void __print(stack<T> s) {
    vector<T> debugVector;
    while (!s.empty()) {
        T t = s.top();
        debugVector.push_back(t);
        s.pop();
    }
    reverse(debugVector.begin(), debugVector.end());
    __print(debugVector);
}
template <typename T>
void __print(queue<T> q) {
    vector<T> debugVector;
    while (!q.empty()) {
        T t = q.front();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
template <typename T, typename... U>
void __print(priority_queue<T, U...> q) {
    vector<T> debugVector;
    while (!q.empty()) {
        T t = q.top();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
void _print() { cerr << "]\n"; }
template <typename Head, typename... Tail>
void _print(const Head &H, const Tail &...T) {
    __print(H);
    if (sizeof...(T))
        cerr << ", ";
    _print(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define debug(...)
#endif


vector<vector<int>> c;
vector<set<int>> adj;
int n;

int bfs(int s, int t, vector<int> &p){
	fill(all(p), -1);
	p[s] = -2;
	
	queue<pair<int, int>> q;
	q.push({s, INF});


	while(!q.empty()){
		int v = q.front().first, w = q.front().second;
		q.pop();

		for(int u: adj[v]){
			if(p[u] == -1 && c[v][u]){
				p[u] = v;
				int new_flow = min(w, c[v][u]);
				if(u == t) return new_flow;
				q.push({u, new_flow});
			}
		}
	}
	return 0;
}

int maxFlow(int s, int t){
	int flow = 0;
	vector<int> p(n);

	int new_flow;

	while(new_flow = bfs(s, t, p)){
		// debug(p);
		flow += new_flow;
		int cur = t;
		while(cur != s){
			int prev = p[cur];
			c[prev][cur] -= new_flow;
			c[cur][prev] += new_flow;
			cur = prev;
		}
	}
	
	return flow;
}

signed main(){
	cin>>n;
	n++;

	c.assign(n, vector<int>(n, 0));
	adj.assign(n, set<int>());
	// vou ter dois vértices "1", um de saída e outro de entrada
	// o de saída será a source e o de entrada a sink
	
	for(int i = 0; i<n-1; i++){
		string s; cin>>s;
		if(s == "*") {
			int v; cin>>v;
			v--;
			if(v == 0) v = n-1; // sink
			adj[i].insert(v);
			c[i][v] = INF;
		} else {
			int k = stoi(s);
			for(int j = 0; j<k; j++){
				int v; cin>>v;
				v--;
				if(v == 0) v = n-1;
				adj[i].insert(v);
				c[i][v]++;
			}
		}
	}
	// debug(adj);
	// Antes de rodar o fluxo, preciso saber se a resposta não é INF
	// ou talvez não
	int r = maxFlow(0, n-1)+1;
	if(r > 100000) cout<<"*"<<endl;
	else cout<<r<<endl;
}