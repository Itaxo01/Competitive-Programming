#include <bits/stdc++.h>
using namespace std;
#define ll long long

#pragma region debug
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
void __print(const A &x)
{
	bool first = true;
	cerr << '{';
	for (const auto &i : x)
	{
		cerr << (first ? "" : ","), __print(i);
		first = false;
	}
	cerr << '}';
}
template <typename A, typename B>
void __print(const pair<A, B> &p)
{
	cerr << '(';
	__print(p.first);
	cerr << ',';
	__print(p.second);
	cerr << ')';
}
template <typename... A>
void __print(const tuple<A...> &t)
{
	bool first = true;
	cerr << '(';
	apply([&first](const auto &...args)
			{ ((cerr << (first ? "" : ","), __print(args), first = false), ...); }, t);
	cerr << ')';
}
template <typename T>
void __print(stack<T> s)
{
	vector<T> debugVector;
	while (!s.empty())
	{
		T t = s.top();
		debugVector.push_back(t);
		s.pop();
	}
	reverse(debugVector.begin(), debugVector.end());
	__print(debugVector);
}
template <typename T>
void __print(queue<T> q)
{
	vector<T> debugVector;
	while (!q.empty())
	{
		T t = q.front();
		debugVector.push_back(t);
		q.pop();
	}
	__print(debugVector);
}
template <typename T, typename... U>
void __print(priority_queue<T, U...> q)
{
	vector<T> debugVector;
	while (!q.empty())
	{
		T t = q.top();
		debugVector.push_back(t);
		q.pop();
	}
	__print(debugVector);
}
void _print() { cerr << "]\n"; }
template <typename Head, typename... Tail>
void _print(const Head &H, const Tail &...T)
{
	__print(H);
	if (sizeof...(T))
		cerr << ", ";
	_print(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...)                                                 \
	cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; \
	_print(__VA_ARGS__)
#else
#define debug(...)
#endif
#pragma endregion

vector<vector<int>> v;
vector<vector<ll>> cp, rp;
int n, m;


inline int id(int i, int j){
	return i*m+j;
}


ll dijkstra(vector<vector<pair<int, ll>>> &adj){
	int start = id(n-1, m-1);
	int end = 0;
	int N = n*m;

	vector<ll> dist(N, LLONG_MAX);
	dist[N-1] = 0;	
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
	pq.push(make_pair(0, N-1));

	while(!pq.empty()){
		auto [w, v] = pq.top(); pq.pop();
		if(v == 0) break;	
		for(auto [u, w1]: adj[v]){
			if(dist[u] > w+w1){
				dist[u] = w+w1;
				pq.push(make_pair(dist[u], u));
			}
		}
	}

	return dist[0];
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	v.resize(n, vector<int>(m));
	cp.resize(m, vector<ll>(n));
	rp.resize(n, vector<ll>(m));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++) cin>>v[i][j];
	}

	for(int i = 0; i<n; i++){
		rp[i][0] = v[i][0];
		for(int j = 1; j<m; j++){
			rp[i][j] = v[i][j] + rp[i][j-1];
		}
	}

	for(int j = 0; j < m; j++){
		cp[j][0] = v[0][j];
		for(int i = 1; i < n; i++){
			cp[j][i] = cp[j][i-1] + v[i][j];
		}
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cp[j][i] = cp[j][i]*cp[j][i];
			rp[i][j] = rp[i][j]*rp[i][j]; // square the values
		}
	}


	vector<vector<pair<int, ll>>> adj(n*m);
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			// do vertice (i, j) posso:
			// ir para (i-1, j) com o custo de cp[j][i-2]
			// ir para (i, j-1) com o custo de rp[i][j-2].
			if(i){
				adj[id(i, j)].push_back(make_pair(
					id(i-1, j), (i >= 2 ? cp[j][i-2] : 0)
				));
			}
			if(j){
				adj[id(i, j)].push_back(make_pair(
					id(i, j-1), (j >= 2 ? rp[i][j-2] : 0)
				));
			}
		}
	}
	// agora que tenho o vetor de adjecências, da para fazer um dijkstra.

	cout<<dijkstra(adj)<<endl;




}
