#include <bits/stdc++.h>
#define ll long long
using namespace std;



// ll rho(ll n){
// 	if(n % 2 == 0) return 2;
// 	ll d, c, x, y;
// 	do {
// 		c = llrand() %n, x = llrand() % n, y = x;
// 		do {
// 			x = add(mul(x, x, n), c, n);
// 			y = add(mul(y, y, n), c, n);
// 			y = add(mul(y, y, n), c, n);
// 			d = __gcd(abs(x - y), n);
// 		} while(d == 1);
// 	}while(d == n);
// 	return d;
// }

ll mod(ll a, ll n){
	return (a % n + n)%n;
}

ll add(ll a, ll b, ll n){
	return mod(mod(a, n) + mod(b, n), n);
}

ll mul(ll a, ll b, ll n){
	ll res = 1;
	a = mod(a, n);
	while(b){ 
		if(b & 1) res = add(res, a, n);
		a = add(a, a, n);
		b >>= 1;
	}
	return res;
}

ll fexp(ll a, ll b, ll n){
	ll res = 1;
	a = mod(a, n);
	while(b){
		if(b & 1) res = mul(res, a, n);
		a = mul(a, a, n);
		b >>= 1;
	}
	return res;
}

ll llrand(){
	return (((ll)rand()) << (ll)33) ^ (ll)rand();
}

tuple<ll, ll, ll> gcd(ll a, ll b) {
	if(b == 0) return make_tuple(a, 1, 0);
	int q, w, e;
	tie(q, w, e) = gcd(b, a % b);
	return make_tuple(q, e, w-e*(a/b));
}

bool rabin(ll n){
	if (n <= 1) return 0;
	if (n <= 3) return 1;
	ll s = 0, d = n-1;
	while (d % 2 ==  0) d /= 2, s++;
	for (int k = 0 ; k<64; k++){
		ll a = (llrand() % (n-3)) +2;
		cout<<"A"<<endl;
		ll x = fexp(a, d, n);
		if (x != 1 && x != n-1){
			for (int r = 1; r < s; r++){
				x = mul(x, x, n);
				if (x == 1) return 0;
				if (x == n-1) break;
			}
			if(x != n-1) return 0;
		}
	}
	return 1;
}

ll pollard_rho(ll n){
	ll x, c, y, d, k;
	int i;
	do{
		i = 1;
		x = llrand() % n, c = llrand() % n;
		y = x, k = 4;
		do {
			if (++i == k) y = x, k *= 2;
			x = add(mul(x, x, n), c, n);
			d = __gcd(abs(x - y), n);
		} while(d == 1 && i < 1e6);
	} while (d == n && i < 1e6); 
	return d;
}

void factorize(ll val, map<ll, int> &fac){
	if (rabin(val)) fac[val]++;
	else {
		ll d = pollard_rho(val);
		factorize(d, fac);
		factorize(val / d, fac);
	}
}

int main(){
	srand(time(0));
	ll a = 135;
	map<ll, int> fac;
	factorize(a, fac);
	for(auto x: fac){
		cout<<x.first<<" "<<x.second<<endl;
	}
}