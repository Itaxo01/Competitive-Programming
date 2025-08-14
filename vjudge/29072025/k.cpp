#include <bits/stdc++.h>
using namespace std;


#pragma region debug
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
#pragma endregion

vector<int> Kuroni, Tfg;
vector<vector<int>> adj;


// Para cada nó armazenarei a soma do Kuroni e a soma do Tfg
// e então simularei o problema

vector<vector<int>> sum;
void compute_sum(int v, int p){
	int v_a = Kuroni[v], v_b = Tfg[v];
	for(int u: adj[v]){
		if(u != p){
			compute_sum(u, v);
			v_a += sum[u][0];
			v_b += sum[u][1];
		}
	}
	sum[v][0] = v_a;
	sum[v][1] = v_a;
}


int res_a, res_b;
// depois de ter a soma de cada subárvore, vou tentar só simular
void dfs(int v, int p, int player = 0){
	// das possíveis subárvores, o jogador irá escolher ir para aquela que: 
	// Tenha a maior soma de sua pontuação, ou, caso haja mais de uma, aquela
	// que tenha a maior de ambas as pontuações.

	res_a += Kuroni[v], res_b += Tfg[v];

	int t = -1; // melhor candidato
	if(player == 0){
		for(int u: adj[v]){
			if(u != p){
				if(t == -1) t = u;
				if(sum[u][0] > sum[t][0]) t = u;
				else if(sum[u][0] == sum[t][0] && sum[u][1] > sum[t][1]) t = u;
			}
		}
	} else {
		for(int u: adj[v]){
			if(u != p){
				if(t == -1) t = u;
				if(sum[u][1] > sum[t][1]) t = u;
				else if(sum[u][1] == sum[t][1] && sum[u][0] > sum[t][0]) t = u;
			}
		}
	}
	if(t == -1) return;
	// continuo navegando para o maior candidato.
	dfs(t, v, (player+1)%2);
}

int main(){
	int n; cin>>n;
	Kuroni.resize(n), Tfg.resize(n);
	for(int &e: Kuroni) cin>>e;
	for(int &e: Tfg) cin>>e;
	adj.assign(n, vector<int>());
	sum.assign(n, vector<int>(2));

	for(int i =0; i<n-1; i++){
		int a, b; cin>>a>>b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	
	compute_sum(0, -1);
	res_a = 0, res_b = 0;

	dfs(0, -1);
	cout<<res_a<<" "<<res_b<<endl;

		
}