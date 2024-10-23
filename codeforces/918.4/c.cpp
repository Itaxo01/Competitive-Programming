#include <bits/stdc++.h>
#define int long long
using namespace std;


void work(){
	int a; cin>>a;
	int sum = 0;
	for(int i = 0; i<a; i++){
		int b; cin>>b;
		sum+=b;
	}
	if(floor(sqrt(sum)) == sqrt(sum)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

}

signed main(){
	int n; cin>>n;
	while(n--){
		work();
	}
}