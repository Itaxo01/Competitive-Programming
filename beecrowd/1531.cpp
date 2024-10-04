#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll mod(ll m, ll n){
    return (m%n+n)%n;
}

struct Matrix{
    ll a,b,c,d;
    Matrix operator* (Matrix m){
        return { a * m.a + b * m.c, a * m.b + b * m.d,
                 c * m.a + d * m.c, c * m.b + d * m.d};
    }
	Matrix operator% (ll m){
		return {mod(a, m), mod(b, m), mod(c, m), mod(d, m)};
	}
};

Matrix fastPow(Matrix m, ll potencia){
    if (potencia <= 0) {
		return {1, 0, 0, 1};

    } else if (mod(potencia, 2) == 0) {
        Matrix x = fastPow(m, potencia/2);
        return (x * x);
    } else {
        Matrix x = fastPow(m, potencia/2);
        return (x * x * m);
    }
}
Matrix fastPow(Matrix m, ll potencia, ll pis){
    if (potencia <= 0) {
		return {1, 0, 0, 1};

    } else if (mod(potencia, 2) == 0) {
        Matrix x = fastPow(m, potencia/2, pis);
        return (x * x)%pis;
    } else {
        Matrix x = fastPow(m, potencia/2, pis);
        return (x * x * m)%pis;
    }
}


ll pisano(ll m)
{
	ll a = 1;
	ll b = 1;
	ll ans = 1;
	
	while (1)
	{
		ll temp = b % m;
		b = (a + b) % m;
		a = temp;
		++ans;
		
		if (a == 1 && b == 1) return ans - 1;
	}
}


int main(){
    ios_base::sync_with_stdio(false);
    std::cout.sync_with_stdio(false);
    cin.tie(NULL);
    int n; int m;
    while(cin>>n>>m){
		int pis = pisano(m);
		if(n!=0){
			Matrix result = fastPow({1, 1, 1, 0}, n-1, pis);
			n = mod(result.a, pis);
			if(n!=0){
				result = fastPow({1, 1, 1, 0}, n-1, m);
				ll total = mod(result.a, m);
				cout<<total<<endl;
			}else cout<<0<<endl;
		}else cout<<0<<endl;
    }
    return 0;
}
