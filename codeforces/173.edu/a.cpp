#include <bits/stdc++.h>
#define int long long
using namespace std;


void work(){
	int n; cin>>n;
	int sum = 1;
	while(n > 3){
		n/=4;
		sum<<=1;
	}
	cout<<sum<<endl;
}

signed main(){
	int tt; cin>>tt;
	while(tt--){
		work();
	}
}