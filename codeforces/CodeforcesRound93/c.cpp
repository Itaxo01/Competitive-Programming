#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
	ll n; cin>>n;
	
	for(ll i = 0; i<n; i++){
		ll a; cin>>a;
		string s; cin>>s;
		map<ll, ll> p = {{0, 1}};
		ll soma = 0;
		ll res = 0;
		for(ll j = 0; j<a; j++){
			soma+=s[j]-'0';
			ll ac = soma-j-1;
			if(p.find(ac)==p.end()) p.insert({soma-j, 0});
			p[ac]++;
			res+=p[ac]-1;
		}
		cout<<res<<endl;
	}
}