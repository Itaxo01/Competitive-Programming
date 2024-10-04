#include<bits/stdc++.h>
#define ll long long
using namespace std; 
int const m = 1e9+7;

ll mod(ll a, ll b) {
	return ((a%b)+b)%b;
}

ll gcdExtended(ll a, ll b, ll* x, ll* y);

ll modInverse(ll A, ll M ){
    ll x, y;
    ll g = gcdExtended(A, M, &x, &y);
    
    ll res = (x % M + M) % M;
    res %= M;
    return res;
}

ll gcdExtended(ll a, ll b, ll* x, ll* y) {

    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }

    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

ll multiMod(ll a, ll b, ll mod) 
{ 
    ll res = 0;
    a %= mod; 
  
    while (b) { 
        if (b & 1) 
            res = (res + a) % mod; 
  
        a = (2 * a) % mod; 
  
        b >>= 1; 
    } 
  
    return res; 
} 
  

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin>>n;
	for(int i = 0; i<n; i++){
		ll a; cin>>a;
		vector<ll> v(a);
        ll soma1 = 0;
		for(int j = 0; j<a; j++){
			cin>>v[j];
            soma1= soma1+v[j];
		}
		ll sum = 0;
		ll count = (a*(a-1))/2;
		for(int j = 0; j<a-1; j++){
            soma1-=v[j];
            sum = (sum + (multiMod(v[j], soma1, m))%m)%m;
            
		}
		ll d = modInverse(count, m);
		ll ans = ((sum%m)*(d%m))%m;
		cout<<ans<<endl;
	}
}