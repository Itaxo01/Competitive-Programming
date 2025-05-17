#include <bits/stdc++.h>
#define int long long
using namespace std;

void work(){
	string s; cin>>s;
	for(int i = 1; i<s.size(); i++){
		if(s[i] == s[i-1]) {
			cout<<1<<endl;
			return;
		}
	}
	cout<<s.size()<<endl;
}


signed main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int tt; cin>>tt;
	while(tt--){
		work();
	}
}