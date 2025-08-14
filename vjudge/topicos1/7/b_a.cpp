#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ll long long
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

int B;

int msb(string &k){
	for(int i = B-1; i>=0; i--) 
		if(k[i] == '1') return i;
	return 0;
}

string str_xor(string &a, string &b){
	string r(B, '.');
	for(int i = 0; i<B; i++){
		if(a[i] == '1' && b[i] == '1') r[i] = '0';
		else if(a[i] == '1' || b[i] == '1') r[i] = '1';
		else r[i] = '0';
	}
	return r;
}

bool is_zero(string &k){
	for(char c: k) 
		if(c == '1') return false;
	return true;
}


set<int> r;
map<int, int> m;
struct Gauss_xor{
	vector<string> base; // store the number that acts as a base for each bit
	vector<vector<int>> table;
	int it = -1;
	int b_size = 0; // 2^b_size = num of different numbers
	Gauss_xor(){
		base.assign(B, "-1");
		table.assign(B, vector<int>());
	}
	bool insert(string &k){
		vector<int> aux;
		++it;
		// debug(k);
		for(int i = 0; i<B; i++){ 
			if(k[i] == '0') continue;
			if(base[i] == "-1") {
				base[i] = k, b_size++;
				table[i] = aux;
				m[i] = it;
				// debug(aux);
				return false;
			}
			k = str_xor(k, base[i]);
			aux.push_back(i);
		}
		if(is_zero(k)){
			r.insert(it);
			// debug(r);
			stack<int> s;
			for(int e: aux) s.push(e), r.insert(m[e]);
			while(!s.empty()){
				// debug(s);
				auto i = s.top(); s.pop();
				for(int e: table[i]){
					if(!r.count(m[e])) s.push(e), r.insert(m[e]);
					else r.erase(m[e]);
				}
				// debug(r);

			}
			return true;
		}
		return false;
	}
};

int main(){
	int n, k; cin>>n>>k;
	B = k+1;

	Gauss_xor g;
	bool res = false;
	for(int i = 0; i<n; i++){
		string s; cin>>s;
		if(res) continue;
		s.push_back('1');
		if(g.insert(s)) res = true;
	}

	if(res){
		int c = 0;
		int Max = r.size();
		for(int i = 0; i<n; i++){
			if(r.count(i)){
				if(c < Max/2) cout<<2;
				else cout<<1;
				c++;
			} else cout<<0;
		}		
		cout<<endl;
	} else{
		cout<<"*"<<endl;
	}
}