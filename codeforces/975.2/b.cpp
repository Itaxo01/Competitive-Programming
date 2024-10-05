#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	ll n; cin>>n;
	while(n--){
		ll a, b; cin>>a>>b;
		
		map<ll, ll> s;
		ll anterior; cin>>anterior;
		for(ll i = 0; i<a-1; i++){
			ll x; cin>>x;
			ll dif = (a-1-i)+i*(a-i);
			ll dif2 = (i+1)*(a-i-1);
			if(s.find(dif)!=s.end()){
				s[dif]++;
			}else{
				s[dif] = 1;
				if(!i) s[dif]++;
			}
			if(s.find(dif2)!=s.end()){
				s[dif2] += (x-anterior-1);
			}else{
				s[dif2] = (x-anterior-1);
			}

			anterior = x;
		}
		for(ll i = 0; i<b; i++){
			ll q; cin>>q;
			ll value = 0;
			if(s.find(q)!=s.end()){
				value = s[q];
			}
			if(!i) cout<<value;
			else cout<<" "<<value;
		}
		cout<<endl;
	}
}