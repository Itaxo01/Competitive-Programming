#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
array<int,4> mul(array<int,4>& a, const array<int,4>& b, int MOD) {
	array<int,4> c={0,0,0,0};	
	c[0] = ((ll)a[0] * b[0] + (ll)a[1] * b[2]) % MOD;
	c[2] = ((ll)a[2] * b[0] + (ll)a[3] * b[2]) % MOD;
	c[1] = ((ll)a[0] * b[1] + (ll)a[1] * b[3]) % MOD;
	c[3] = ((ll)a[2] * b[1] + (ll)a[3] * b[3]) % MOD;
 
	return c;
}
 
array<int,4> fpow(array<int,4> m, ll b, int MOD) {
	array<int,4> x = {1,0,0,1};
	while(b) {
		if (b&1) x=mul(x,m,MOD);
		m=mul(m,m,MOD);
		b >>= 1;
	}
	return x;
}
 
ll fpow(ll a, ll b, ll MOD) {
	ll x=1;
	while(b) {
		if (b&1) x=(__int128)a*x%MOD;
		a=(__int128)a*a%MOD;
		b >>= 1;
	}
	return x;
}
 
ll prime_period(int p) {
	return p == 5 ? 20 : (ll)p*p-1;
}
 
signed main() {
	int a,b,MOD; cin>>a>>b>>MOD;
 
	int x=MOD;
	ll period=1;
	for (int p=2; p*p <= x; p++) {
		if (x % p) continue;
		int e;
		int pow;
		for (e=0,pow=1;x%p==0; x/=p, e++, pow*=p);

		period=lcm(period, prime_period(p) * (pow/p));
	}
 
	if (x != 1) period=lcm(period, prime_period(x));
 
	assert(period <= 1000000018000000080ll);
 
	ll n = fpow(a,b,period);
	assert(n >= 0);
	int ans = fpow(array<int,4>{0,1,1,1}, n, MOD)[1];
	assert(ans >= 0);
		cout<<period<<" "<<n<<endl;

	cout << ans << endl;
}