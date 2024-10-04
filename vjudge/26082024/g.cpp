#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n;
	for(int i = 0; i<n; i++){
		string s; cin>>s;
		string new_s = "";
		char anterior = ' ';
		if(s.size()==1) cout<<s<<s<<endl;
		else{
			if(s[0]!=s[1]){ new_s += s[0]; new_s += s[0];}
			else new_s += s[0];
			for(int e = 1; e<s.size()-1; e++){
				if(s[e]!=s[e-1] && s[e]!=s[e+1]){new_s += s[e]; new_s+=s[e];}
				else new_s += s[e];
			}
			if(s[s.size()-1]!=s[s.size()-2]){new_s += s[s.size()-1]; new_s+=s[s.size()-1];}
			else new_s += s[s.size()-1];
			cout<<new_s<<endl;
		}
	}
}
