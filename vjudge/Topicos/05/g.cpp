#include <bits/stdc++.h>

using namespace std;

int main(){
	while(true){
		int n; cin>>n;
		bool first = true;
		if(!n) break;
		string s = "";
		while(n--){
			string a; cin>>a;
			
			if(a!="0"){
				if(first){
					first = false;
					s+=a;
				}else{
					s+=" "+a;
				}
			}
		}
		if(!s.size()) cout<<"0"<<endl;
		else cout<<s<<endl;
	}
}