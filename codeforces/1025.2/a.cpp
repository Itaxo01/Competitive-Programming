#include <bits/stdc++.h>
#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;


void work(){
	int n; cin>>n;
	vector<int> v(n);
	for(int i = 0; i<n; i++){
		cin>>v[i];
	}
	bool one = false, zero = false;
	for(int i = 0; i<n-1; i++){
		if(v[i] == v[i+1] && v[i] == 0) {
			cout<<"YES"<<endl; 
			return;
		}
		if(v[i] == 1) one = true;
		if(v[i] == 0) zero = true;
		
	}
	if(v[n-1] == 1) one = true;
	if(v[n-1] == 0) zero = true;
	if(!one || !zero) {
		cout<<"YES"<<endl;
		return;
	}
	cout<<"NO"<<endl;
}

signed main(){
	fastio
	int tt; cin>>tt;
	while(tt--){
		work();
	}
}