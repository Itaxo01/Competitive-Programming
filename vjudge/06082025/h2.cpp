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
const int M = 1000000009;

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


vector<int> v;
map<pair<ll, ll>, ll> m;
ll solve(ll p, ll x){
	auto P = make_pair(p, x);
	if(p == 0) return v[x];
	if(x <= 0) return 1LL;
	if(m.count(P)) return m[P];

	m[P] = mult(solve(p, x-1), solve(p-1, x));
	return m[P];
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tt; cin>>tt; 
	while(tt--){
		int n, q; cin>>n>>q;
		v.resize(n+1);
		m.clear();
		for(int i = 1; i<=n; i++) cin>>v[i];


		// Não me parece necessariamente difícil, acho que basta entender a relação dos números multiplicados. 
		// no p(1), o array fica assim:
		// v1, v1*v2, v1*v2*v3, v1*v2*v3*v4 ..... 
		// ou seja, para uma posição X cada elemento até X aparece uma vez na multiplicação
		// no p(2), o array fica assim:
		// v1, v1*(v1*v2), (v1*v1*v2)*(v1*v2*v3)
		// para uma posição X, o v1 aparece X vezes
		// v2 aparece X-1 vezes
		// v3 aparece X-2) vezes, etc, enquanto X for maior que N em vN
		// ou seja, cada elemento é uma PA de fator 1 que começa em 1 e tem portanto seu valor final sendo (1 + 1*(X-N))
		// p(3):
		// v1, v1*(v1*v1*v2), (v1*v1*v1*v2)*((v1*v1*v1*v2*v2*v3))
		// Aqui, cada elemento é uma PA de fator 2
		// dessa forma, cada elemento aparece (1 + 2*(X-N)) vezes
		// vou acreditar que isso se generaliza para todos os p's, (inclusive o P1, já que cada elemento aparece (1 + 0*(X-N)) vezes)


		// utilizando o exemplo:
		// V = 1, 2, 3, 4, 5
		// p(1) = 1, 2, 6, 24, 120 -> v1, v1*v2, v1*v2*v3, v1*v2*v3*v4, v1*v2*v3*v4*v5
		// p(2) = 1, 2, 12, 288, 34560 -> v1, v1*v1*v2, v1*v1*v2 * v1*v2*v3, v1*v2*v3*v4 * (v1*v1*v2 * v1*v2*v3)
		// no p(2, 4) eu tenho v1^4 * v2^3 * v3^2 * v4^1
		// p(3) = 1, 2, 24, 6912, 238878720 -> v1, v1*v1*v1*v2, v1*v1*v1*v2 * v1*v1*v2 * v1*v2*v3, v1*v2*v3*v4 * (v1*v1*v2 * v1*v2*v3) * v1*v1*v1*v2 * v1*v1*v2 * v1*v2*v3
		// v3*v4 * (v3) **v3
		// v1^10 * v2^6 * v3^3 * v4
		// p(4) = 1, 2, 48, 331776 -> v1, v1*v1*v1*v1*v2, v1*v1*v1*v2 * v1*v1*v2 * v1*v2*v3 * v1*v1*v1*v1*v2, v1*v1*v1*v2 * v1*v1*v2 * v1*v2*v3 * v1*v1*v1*v1*v2 *  v1*v2*v3*v4 * (v1*v1*v2 * v1*v2*v3) * v1*v1*v1*v2 * v1*v1*v2 * v1*v2*v3
		// *** * ** * ** * **** *  ***v4 * (** * **) * *** * ** * **
		// v1^19 * v2 ^ 10 * v3^4 * v4  




		for(int i = 0; i<q; i++){
			int k, x; cin>>k>>x;
			cout<<solve(k, x)<<endl;

			// ll r = 1;
			// ll exp = 1; // exp representa o expoente atual
			// ll acc = 0; // acc representa o incremento atual do expoente, começa em k-1 e aumenta a esse mesmo ritmo
			// for(int j = x; j>=1; j--){
			// 	r = mult(r, fast_pow(v[j], exp));
			// 	acc += k-1;
			// 	exp += acc;
			// }
			// cout<<r<<endl;
		}
	}
}