#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n; cin>>n;
	while(n--){
		ll a; cin>>a;
		ll i = 0; ll f = 2e18;
		while(i<f){
			ll m = (i+f)/2;
			ll t = m - floor(sqrt((long double)m));
			if(t>=a) f = m;
			else i = m+1;
		}
		cout<<(i+f)/2<<endl;
	}
}