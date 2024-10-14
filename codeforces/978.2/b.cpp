#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	int n; cin>>n;
	while(n--){
		ll a, b; cin>>a>>b;
		ll sum = 0;
		ll maior = 0;
		for(int i = 0; i<a; i++){
			ll c; cin>>c;
			maior = max(maior, c);
			sum+=c;
		}
		if(b*maior>=sum){
			cout<<maior<<endl;
			continue;
		} else{
			ll res = ceil(sum/(double)b);
			cout<<res<<endl;
		}
	}
}