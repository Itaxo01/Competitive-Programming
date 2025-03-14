#include <bits/stdc++.h>
using namespace std;


int main(){
	int a, b, c; cin>>a>>b>>c;
	bool res = true;
	for(int i = 0; i<a; i++){
		string s1, s2;
		cin>>s1>>s2;
		bool has_risk = false;
		for(auto e: s2){
			if(e == '*') {
				has_risk = true;
				break;
			}
		}
		if(has_risk){
			for(auto e:s1){
				if(e != '*') {
					res = false;
					break;
				}
			}
		}
	}
	if(res) cout<<"Y\n";
	else cout<<"N\n";
}