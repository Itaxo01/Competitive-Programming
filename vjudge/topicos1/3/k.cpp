#include <bits/stdc++.h>
using namespace std;

bool check(string &e, vector<int> &m){
	for(auto c: e){
		if(m[c-'A'] == 0) return false;
	} return true;
}

int main(){
	int n; cin>>n;
	vector<string> v(n);
	vector<int> m(26, 0);
	for(int i =0 ; i<n; i++){
		string s; cin>>s;
		v[i] = s;
		m[s[0]-'A']++;
	}
	for(auto e:v){
		if(check(e, m)){
			cout<<"Y\n"; return 0;
		}
	}
	cout<<"N\n";
}