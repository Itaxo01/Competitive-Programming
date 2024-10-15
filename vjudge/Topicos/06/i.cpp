#include <bits/stdc++.h>
using namespace std;
int t;
int c1;
pair<int, int> m1;

pair<int, int> min(pair<int, int> a, pair<int, int> b){
	if(abs(a.first) == abs(b.first)) return a.second < b.second ? a : b;
	return abs(a.first) < abs(b.first) ? a : b;
}

int solve(int a, int b, int c[], bitset<101> bs, map<pair<int, int>, int> &m){
	if(m.find({a, b}) != m.end()) return m[{a, b}];
	if(b == 0) return a;
	if(m1.first<0 && a<m1.first) return m[{a, b}] = INT_MAX;
	m[{a, b}] = INT_MAX;
	for(int i = 0; i<c1; i++){
		if(bs.test(i)) continue;
		bs.set(i);
		m[{a, b}] = min(m[{a, b}], abs(solve(a - c[i], b - 1, c, bs, m)));
		m1 = min(m1, {a, b});
		bs.reset(i);
	}
	return m[{a, b}];
}


int main(){
	int n; cin>>n;
	while(n--){
		cin>>t;
		cin>>c1;
		int c[c1];
		for(int i = 0; i<c1; i++){
			cin>>c[i];
		}
		map<pair<int, int>, int> m;
		bitset<101> bs; bs.reset();
		m1 = {INT_MAX, INT_MAX};
		solve(t, c1, c, bs, m);
		cout<<t-m1.first<<" "<<c1-m1.second<<endl;
	}

}