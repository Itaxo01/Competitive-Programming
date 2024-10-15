#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll solve(int a, int b, int c, map<vector<int>, ll> &m){
	vector<int> v = {a, b, c};
	if(m.find(v) != m.end()) return m[v];
	
	if(b == 0){
		if(a == 0) return 1;
		return 0;
	}

	for(int i = 1; i<=c; i++){
		m[v] += solve(a-i, b-1, c, m);
	}
	return m[v];
}


int main(){	
	int a, b, c;
	string s;
	while(getline(cin, s)){
		if(s == "") break;
		stringstream ss(s);
		ss >> a >> b >> c;
		if(b*c < a){
			cout<<0<<endl;
			continue;
		}
		if(a == b && a == c){
			cout<<1<<endl;
			continue;
		}
		vector<int> v;
		map<vector<int>, ll> m;
		cout<<solve(a, b, c, m)<<endl;
		
	}	
}