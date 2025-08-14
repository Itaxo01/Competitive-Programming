#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;



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

typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}
vi conv(const vd& a, const vd& b) {
	if (a.empty() || b.empty()) return {};
	vi res(sz(a) + sz(b) - 1);
	int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
	vector<C> in(n), out(n);
	copy(all(a), begin(in));
	rep(i,0,sz(b)) in[i].imag(b[i]);
	fft(in);
	for (C& x : in) x *= x;
	rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	rep(i,0,sz(res)) res[i] = (int)round(imag(out[i]) / (4 * n));
	return res;
}

int mod(int a, int b){
	return (a%b+b)%b;
}

int main(){
	int n; cin>>n;
	vector<double> a(n), b(n);
	vector<double> da(n), db(n);
	
	int i = 0;
	for(double &e: a){
		cin>>e;
		da[i++] = e ? 0 : 1;
	}
	i = 0;
	for(double &e: b){
		cin>>e;
		db[i++] = e ? 0 : 1;
	}

	
	
	// com isso, a "fusão" da pizza A com a B em um deslocamento j(mod n), é tal que
	// para cada indice i, a pizza resultante tem valor:
	// a[i] * db[i+j] + b[i] * da[i+j]. Isso faz com que, caso haja valor em ambos, ambos zeram visto que da[i+j] e db[i+j] será zero. Caso não haja valor em ambos, também zera pois a[i] == 0 e b[j] == 0, e caso haja valor em somente um deles, a soma resultará neste um.
	
	// Até ai tranquilo, porém fazer essa soma de forma usual é muito custoso, pois seria quadrático fazer para cada possivel posição.
	
	// a solução é usar FFT para fazer a correlação rápida, que basicamente faz essa comparação para todos os possiveis deslocamentos simultaneamente em tempo O(NlogN)
	
	// a correlação(A, B) é basicamente a convolução(A, reverse(B))
	for(int i = 0; i<n; i++){
		a.push_back(a[i]);
		b.push_back(b[i]);
		// da.push_back(da[i]);
		// db.push_back(db[i]);
	}

	reverse(db.begin(), db.end());
	reverse(da.begin(), da.end());
	auto r1 = conv(a, db);
	debug(r1);
	auto r2 = conv(b, da);
	debug(r2);


	ll res = 0;
	for(int i = 0; i<n; i++){
		int s = (n - i) % n;
		// cout<<(ll)round(r1[n-1+i]+r2[n-1+s])<<" ";
		res = max(res, (ll)round(r1[n-1+i]+r2[n-1+s]));
		// res = max(res, (ll)round(r1[i]+r2[i]));
	}
	// cout<<endl;
	cout<<res<<endl;


}