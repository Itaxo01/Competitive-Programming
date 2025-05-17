#include <bits/stdc++.h>
#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;


void work(){
	int n, m, p, q; cin>>n>>m>>p>>q;
	if(n % p == 0){
		if(q * (n/p) == m) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	} else cout<<"YES"<<endl;
}

signed main(){
	fastio
	int tt; cin>>tt;
	while(tt--){
		work();
	}
}