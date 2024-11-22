#include <bits/stdc++.h>
using namespace std;

int mod = 131071;

int solve(string s){
	int r = 1;
	int res = 0;
	int pos = s.size()-2;
	while(pos>=0){
		if(s[pos] == '1'){
			res = (res+r)%mod;
		}
		r = (r*2)%mod;
		pos--;
	}
	return res;
}


int main(){
	string s;
	while(cin>>s){
		string aux;
		while(s[s.size()-1] != '#'){
			cin>>aux;
			s += aux;
		}
		if(!solve(s)) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
}