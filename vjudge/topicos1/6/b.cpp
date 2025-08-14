#include <bits/stdc++.h>
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


struct SparseTable {
  vector<vector<int>> st;
  vector<int> log;
  bool is_min;
  int n, k;
  SparseTable(vector<int> &a, bool is_min_) {
   is_min = is_min_; 
	n = a.size();
    k = log2(n)+1;
    st.assign(k, vector<int>(n));
    for(int i=0;i<a.size();i++) {
      st[0][i] = a[i];
    }
    log.assign(n+1, 0);
    for(int i = 2; i<=n; i++) log[i] = log[i/2]+1;
    // It's possible to construct the st with any operation that satisfies f((a, b), c) = f(a, (b, c))
    // just switch the min for the desired function
    for (int i = 1; i <= k; i++)
      for (int j = 0; j + (1 << i) <= n; j++)
	 		if(is_min) st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]); 
	 		else st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]); 
	}
  int query(int l, int r) {
    int i = log2(r - l + 1);
    if(is_min) return min(st[i][l], st[i][r - (1 << i) + 1]);
    else return max(st[i][l], st[i][r - (1 << i) + 1]);
  }
};


signed main(){
	int n; cin>>n;
	vector<int> v(n);
	for(auto &a: v) cin>>a;
	vector<int> R(n), L(n); // primeiro menor para a direita, primeiro menor para a esquerda
	
	stack<int> s;
	for(int i = 0; i<n; i++){
		if(v[i] != -1){
			if(!s.empty()){
				while(!s.empty() && v[s.top()] >= v[i]) s.pop();
			}
			if(!s.empty()) L[i] = s.top();
			else L[i] = 0;
			s.push(i);
			
			continue;
		}
		L[i] = 0;
	}
	while(!s.empty()) s.pop();

	for(int i = n-1; i>=0; i--){
		if(v[i] != -1){
			if(!s.empty()){
				while(!s.empty() && v[s.top()] >= v[i]) s.pop();
			}
			if(!s.empty()) R[i] = s.top();
			else R[i] = n-1;

			s.push(i);
			continue;
		}
		R[i] = n-1;
	}

	SparseTable stL(L, false), stR(R, true);

	bool res = false;
	for(int sz = 3; sz<=n; sz++){
		int last = n%sz;
		last = last == 0 ? sz : last;
		if(last < 3) continue;
		// vou tentar dividir o segmento em partes de tamanho K, com a ultima tendo tamanho last
		// se todas as partes forem válidas, é possível fazer
		
		res = true;
		for(int t = 0; t <= n/sz; t++){
			// intervalo de t*sz até t*sz + sz - 1;
			int l = t*sz;
			int r = min(l + sz - 1, n-1);
			if(l < r)
				if(stL.query(l, r) + 1 > stR.query(l, r)-1) {
					res = false;
					break;
				}
		}
		if(res) break;
	}
	if(res) cout<<"Y"<<endl;
	else cout<<"N"<<endl;
}