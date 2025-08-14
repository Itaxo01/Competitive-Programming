#include<bits/stdc++.h>
#define ll long long
using int128 = __int128;
using namespace std;

ll mod(ll x, ll m) {
    return ((x%m)+m)%m;
}

ll mod(int128 x, ll m){
	return ((x%m)+m)%m;
}

struct Matrix {
    ll a, b, c, d;
	 Matrix(ll a, ll b, ll c, ll d) : a(a), b(b), c(c), d(d) {} 
	 Matrix(){}
};

Matrix mult(Matrix &A, Matrix &B, ll m){
	return Matrix(
            mod((int128)(A.a) * (int128)B.a + (int128)A.b * (int128)B.c, m), 
            mod((int128)(A.a) * (int128)B.b + (int128)A.b * (int128)B.d, m),
            mod((int128)(A.c) * (int128)B.a + (int128)A.d * (int128)B.c, m),
            mod((int128)(A.c) * (int128)B.b + (int128)A.d * (int128)B.d, m)
			);
}

Matrix I(1, 1, 1, 0);
Matrix Mpow(ll n, ll m) {
    if (n <= 0) return Matrix(1, 0, 1, 0);
    if (n == 1) return Matrix(1, 1, 1, 0);
    

    Matrix total = Mpow(n/2, m);
    if (n%2) {
		Matrix p1 = mult(I, total, m);
        return mult(p1, total, m);
    } else {
        return mult(total, total, m);
    }
}

ll f_pow(ll a, ll b, ll m){
    ll res = 1;
    while(b){
        if(b & 1) res = ((int128)res*(int128)a)% m;
        a = ((int128)a*(int128)a)%m;
        b>>=1;
    }
    return res;
}

void factorize(ll a, map<ll, int> &factors){
  for(int i = 2; i*i<=a; i++){
    while(a%i == 0){
      factors[i]++;
      a/=i;
    }
  }
  if(a > 1) factors[a]++;
}

ll pisano_(ll p){
   
	
	if(p == 2) return 3;
	if(p == 3) return 8;
	if(p == 5) return 20;
	if(p % 5 == 1 || p % 5 == 4) {
		return p-1;
	}
	else {
		return (ll)p*p-1;
	}

    map<ll, int> factors;
	 ll period;
    if(p % 5 == 1 || p % 5 == 4) {
      period = p-1;
		factorize(p-1, factors);
    } else {
      period = p*p-1;
      factorize(p-1, factors);
      factorize(p+1, factors); // p^2 - 1
    }

	 for(auto [factor, exp] : factors){
		for(int i = 0; i<exp; i++){
			Matrix r = Mpow(period/factor, p);
			if(r.d == 0 && r.c == 1) period /= factor;
			else break;
		}
	 }
	 return period;
}

ll pisano_(int p, int k){
	return (ll)pow(p, k-1)*pisano_(p);
}

ll pisano(ll m){
    map<ll, int> f;
    factorize(m, f);
    ll r = 1;
    for(auto [a, b]: f){
		r = lcm(r, pisano_(a, b));
    }

    return r;
}

signed main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b, M; cin>>a>>b>>M;
    if(M == 1) cout<<0<<endl;
    else {
		// Matrix r = Mpow(1, 10000);
		// cout<<r.a<<" "<<r.b<<" "<<r.c<<" "<<r.d<<endl;
		ll k = pisano(M);
		ll ab = f_pow(a, b, k);
		cout<<Mpow(ab, M).b<<endl;
    }

    
}