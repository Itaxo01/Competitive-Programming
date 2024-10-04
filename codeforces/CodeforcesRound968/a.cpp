#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	for(int i = 0; i<n; i++){
		int a; cin>>a;
		string s; cin>>s;
		if(s[0]!=s[s.size()-1]) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}