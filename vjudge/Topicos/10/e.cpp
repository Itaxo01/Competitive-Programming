#include <bits/stdc++.h>
#define ll long long
using namespace std;

int mod = 1000000;

struct Matriz{
	ll a, b, c, d;
	Matriz operator*(Matriz m){
		return {(a*m.a + b*m.c)%mod, (a*m.b + b*m.d)%mod, 
				(c*m.a + d*m.c)%mod, (c*m.b + d*m.d)%mod};
	}
};


Matriz fastPow(Matriz m, int n){
	if(n <= 0) return {1, 0, 0, 1};
	Matriz aux = fastPow(m, n/2);
	if(n%2 == 0) return aux*aux;
	return aux*aux*m;
}

int main(){
	int a, b; 
	while(cin>>a>>b){
		mod = 1 << b;
		Matriz m = {1, 1, 1, 0};
		Matriz res = fastPow(m, a);
		cout<<(res.b)%mod<<endl;
	}
}