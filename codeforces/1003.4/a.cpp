#include <bits/stdc++.h>
#define int long long
using namespace std;

void work(){
	string s; cin>>s;
	string aux = s.substr(0, s.size()-2) + 'i';
	cout<<aux<<endl;
}


signed main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int tt; cin>>tt;
	while(tt--){
		work();
	}
}