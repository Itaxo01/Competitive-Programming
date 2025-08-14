#include <bits/stdc++.h>
// #define int long long
#define no {cout<<"NO\n"; }
#define yes {cout<<"YES\n"; ;}
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define md 998244353

using namespace std;

#pragma region debug
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
#pragma endregion


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int l, c; cin>>l>>c;
	vector<vector<int>> m(l, vector<int>(c));

	vector<int> R(l), C(c); // vetores que representam a permutação das linhas e colunas
	
	bool invalid = false;
	for(int i = 0; i<l; i++){
		int menor = INT_MAX, maior = 0;
		for(int j = 0; j<c; j++){
			cin>>m[i][j];
			maior = max(maior, m[i][j]);
			menor = min(menor, m[i][j]);
			if((m[i][j]-1) % c == 0) { // este elemento representa sua linha na permutação das linhas
				int k = (m[i][j]-1)/c;
				R[k] = i; // a linha k está em i;
			}
		}
		if(maior-menor != c-1) invalid = true;
	}

	if(invalid) {
		cout<<"*\n";
		return 0;
	}

	for(int i = 0; i<c; i++){
		C[m[R[0]][i]-1] = i;
	}
	
	for(int i = 0; i < l; i++){
		for(int j = 0; j<c; j++){
			// if(j) cout<<" ";
			// cout<<m[R[i]][C[j]];
			if(R[i] >= 0 && R[i] < l && C[j] >= 0 && C[j] < c){
				if(m[R[i]][C[j]] != c*i+j+1) invalid = true;
			} else invalid = true;
		}
		// cout<<endtl;
	}
	// não vai ser possivel quando não houver todos os elementos em C ou em R
	if(invalid) cout<<"*"<<endl;
	else {
		int swaps = 0;
		for(int i = 0; i<l; i++){
			while(R[i] != i) {
				swaps++;
				swap(R[i], R[R[i]]);
			}
		}

		for(int i = 0; i<c; i++){
			while(C[i] != i) {
				swaps++;
				swap(C[i], C[C[i]]);
			}
		}
		cout<<swaps<<endl;
	}
}
