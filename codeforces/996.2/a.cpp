#include <bits/stdc++.h>
using namespace std;

void work(){
	int a, b, c; cin>>a>>b>>c;
	if(abs(b-c-1) % 2 == 1) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}


int main(){
	int tt; cin>>tt;
	while(tt--){
		work();
	}
}