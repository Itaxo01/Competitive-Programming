#include <bits/stdc++.h>
using namespace std;


int main(){
	int a; cin>>a;
	map<int, pair<int, int>> m;
	for(int i = 0; i<2*a; i++){
		string s; cin>>s;
		if(s[0] == '+'){
			m[s[1]-'0'].first = i;
		} else{
			m[s[1]-'0'].second = i;
		}
	}
}