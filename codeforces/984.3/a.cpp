#include <bits/stdc++.h>
#define int long long
using namespace std;


void work(){
	int a; cin>>a;
	int anterior = 0;
	bool res = true;
	for(int i = 0; i<a; i++){
		int c;cin>>c;
		if(i>0){
			int d = abs(c-anterior);
			if(d!=5 && d!=7){
				res = false;
			}
		}	
		anterior = c;
	}
	if(res) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}

signed main(){
	int n; cin>>n;
	while(n--) work();
}