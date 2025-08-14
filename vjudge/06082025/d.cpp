#include <bits/stdc++.h>
#define ll long long 
using namespace std;


int N;
vector<ll> f;
vector<ll> v;


void solve(int a, int b, int c){
	if(a <= N){
		f[a-1] += c*v[b-1];
	} else {
		c = c*v[b-1];
		for(int i = 1; i<=N; i++){
			solve(a-i, i, c);
		}
	}
}

ll solve(ll k){
	if(k <= N) return v[k-1];
	
	for(int i = 1; i<=N; i++){
		solve(k-i, i, 1);
	}

	return 1;
}

int main(){

	ll m; cin>>N>>m;

	v.assign(N, 0);
	for(ll &e: v) cin>>e;

	f.assign(N, 0);
	solve(m);
	for(int i = 0; i<N; i++){
		cout<<f[i]<<" ";
	} cout<<endl;
	// da para escrever F(X) como uma relação de F(1, k1) * F(2, k2) ... * F(N, kn)
	/*
		EX:
		v = 2, 3
		F(5) :=
				F(4, 1) * F(3, 2) -> F(2)^14*F(1)^12*F(2)^6*F(1)^9-> F(1)^21*F(2)^20
		F(4) :=
				F(3, 1) * F(2, 2) -> F(2)^4 * F(1)^6 * F(2)^3 -> F(1)^6 * F(2)^7
		F(3) :=
				F(2, 1) * F(1, 2) -> F(2)^2 * F(1)^3
		===
		F(4) = F(1)^6 * F(2)^7 = 139968
			                  ^ esse número surge da acomulação dos fatores descendo na árvore, o F(3, 1) tem o expoente 2, que se multiplica quando chega no F(2, 1) com o expoente 2 para virar 4, e se soma com o F(2, 2) com o expoente 3 para virar 7 
		F(5) = F(1)^12 * F(2)^14 
		
	*/
	// Isso nos dá uma dica de que a solução envolve desmembrar o número maior em seus fatores de 1 a N, porém isso ainda precisa ser feito de forma no máximo logaritmica.
	vector<int> f(N);





}