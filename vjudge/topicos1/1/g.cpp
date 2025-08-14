// #pragma GCC optimize ("O2")
#include <bits/stdc++.h>
#define ld double
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin>>n;
	// para cada número, vou ter a probabilidade de voltar para ele mesmo sendo
	// igual a soma da probabilidade de seus divisores
	
	// Começando de n até 1, o valor esperado de um número sera 1 + x*(1/(1-x)),
	// onde x é a probabilidade de voltar para ele mesmo.

	// o K irá somar seu valor esperado em todos os seus divisores, e dessa forma
	// a resposta estará no número 1.
	vector<int> W_i(n+1);
	ld w = 0;
	for(int i = 1; i<=n; i++){
		cin>>W_i[i]; 
		w+=W_i[i];
	}
	// Chance de cada slot
	vector<ld> W(n+1);
	for(int i = 1; i<=n; i++){
		W[i] = W_i[i]/w;
	}

	// Chance de voltar para si mesmo
	vector<ld> p(n+1);
	vector<unordered_set<int>> d(n+1); // divisores de K
	for(int i = 1; i<=n; i++){
		for(int k = 1; k*k<=i; k++){
			if(i % k == 0) {
				if(!d[i].count(k)){
					d[i].insert(k);
					p[i] += W[k];
				}
				int e = i/k;
				if(!d[i].count(e)){
					p[i] += W[e];
					d[i].insert(e);
				}
			}
		}
		// for(int k = i; k <=n; k+=i){
		// 	d[k].insert(i);
		// }
		// cout<<i<<" "<<p[i]<<endl;
		// for(int k: d[i]) cout<<k<<endl;
	}
	// for(int i = 1; i<=n; i++){
	// 	d[i].insert(i);
	// 	p[i] += W[i];
	// 	cout<<i<<" "<<p[i]<<endl;
	// }
	vector<ld> E(n+1, 0.0); // Valor esperado de cada posição
	for(int c = n; c>=1; c--){
		E[c] = (E[c] + p[c])/(1-p[c]); // Ek = p[k]*(1+Ek) + Ez // z > k && k | z
												// -> Ek-p[k]*Ek = p[k] + Ez
												// -> Ek = (p[k]+Ez)/(1-p[k]);
		for(int a: d[c]) {
			if(a < c){
				// preciso achar todo b tal que LCM(a, b) == c
				int t = c/a;
				for(int g: d[a]){
					int b = t*g;
					if(gcd(a/g, t) == 1)
						E[a] += W[b]*(1 + E[c]);
				}
			}
		}
		// cout<<i<<" "<<E[i]<<endl;
	}

	printf("%.10f\n", E[1]);
	
}