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
const int M = 1000000007;

inline ll mult(ll a, ll b){
	return (a*b)%M;
}

inline ll fast_pow(ll a, ll b){
	ll r = 1;
	while(b){
		if(b & 1) r = mult(r, a);
		a = mult(a, a);
		b >>= 1;
	}
	return r;
}



signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tt; cin>>tt; 

	vector<vector<ll>> P(1001, vector<ll>(1001));
	for(int i = 0; i<=1000; i++){
		for(int j = 0; j<=1000; j++){
			if(!i || !j) P[i][j] = 1LL;
			else {
				P[i][j] = (P[i-1][j] + P[i][j-1])%(M-1);
			}
			// A lógica vem disso aqui, depois de muito trabalho braçal, os números indicam os expoentes dos fatores envolvidos
			// 1, 1, 1, 1, 1.. pa(1)
			// 1, 2, 3, 4, 5.. pa(2)
			// 1, 3, 6, 10, 15..pa(3)
			// 1, 4, 10, 20, 35 pa(4)
			// 1, 5, 15, 35, 70 pa(5)
		}
	}
	while(tt--){
		int n, q; cin>>n>>q;
		vector<ll> v(n);
		for(ll &e: v) cin>>e;




		for(int i = 0; i<q; i++){
			ll k, x; cin>>k>>x;
			k--; x--;
			ll r = 1;
			for(int i = 0; i<=x; i++){
				r = mult(r, fast_pow(v[i]%M, P[k][x-i]%(M-1)));
			}
			cout<<r<<endl;
		}
	}
}

