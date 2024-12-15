#include <bits/stdc++.h>
#define int long long
using namespace std;


bool work(){
	int a; cin>>a;
	int sump = 0, sumi = 0;
	for(int i = 0; i<a; i++){
		int b; cin>>b;
		if(i & 1) sumi += b;
		else sump += b;
	}
	if(sump % ((a+1)/2) != 0) return false;
	if(sumi % ((a)/2) != 0) return false;
	if(sump/((a+1)/2) != sumi/((a/2))) return false;
	return true;
}

signed main(){
	int tt; cin>>tt;
	while(tt--){
		if(work()) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}