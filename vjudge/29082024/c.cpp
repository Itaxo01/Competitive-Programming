#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll Mod(ll a) {
	return ((a%mod)+mod)%mod;
}

// Function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll* x, ll* y);

// Function to find modulo inverse of a
ll modInverse(ll A, ll M ){
    ll x, y;
    ll g = gcdExtended(A, M, &x, &y);
    
        // m is added to handle negative x
	ll res = (x % M + M) % M;
    
	return res;
}

// Function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll* x, ll* y) {

    // Base Case
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }

    // To store results of recursive call
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}



long long fastPow(long long a, long long b){
	long long res = 1;
	while(b){
		if(b&1) res = Mod((res*a));
		a = Mod(a*a);
		b>>=1;
	}
	return res;
}

long long fact(long long n, long long k){
	long long res = 1;
	for(long long i = n; i>k; i--){
		res = Mod(res*Mod(i));
	}
	return res;
}

int main(){
	int n; cin>>n;
	while(n--){
		long long a, b; cin>>a>>b;
		if(a-b>=365){
			cout<<0<<endl;
			continue;
		}
		long long p = Mod(fact(a, b)*365*fact(364, 364-(a-b)));
		long long q = Mod(fastPow(365, a)*fact(a-b, 0));
		cout<<Mod((p*modInverse(q, mod)))<<endl;

	}
}