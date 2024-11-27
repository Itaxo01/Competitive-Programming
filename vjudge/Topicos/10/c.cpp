#include <bits/stdc++.h>
#define ll long long
using namespace std; 

void factorize(int a, map<int, int> &factors){
	for(int i = 2; i*i<=a; i++){
		while(a%i == 0){
			factors[i]++;
			a/=i;
		}
	}
	if(a > 1) factors[a]++;
}

bool solve(int a, map<int, int> &f){
	for(auto e: f){
		int n = e.first;
		for(int i = 1; i*n <= a; i++){
			int k = 1;
			int aux = i;
			while(aux % n == 0){
				k++;
				aux /= n;
			}
			f[n] -= k;
			if(f[n] <= 0) break;
		}
		if(f[n] > 0) return false;
	}
	return true;
}

int main(){
	int a, b;
	while(cin>>a>>b){
		// A ideia é: se b for primo, b só divide a! se a >= b.
		// Caso b não seja primo, pegamos os fatores primos dele e contamos se
		// há a quantidade em a!.
		
		// Acredito que não haja a necessidade de somar todos os fatores de 1
		// até a, até por que isso causaria um TLE (a vai até 2e9).

		// Por isso vou tentar fazer uma espécie de crivo
		// Se B precisar de três vezes o fator 3 e uma vez o fator 5 (135),
		// verifico se há três múltiplos de 3 menores igual a a, e um múltiplo de 5 
		map<int, int> f;
		factorize(b, f);


		if(solve(a, f)) printf("%d divides %d!\n", b, a);
 		else printf("%d does not divide %d!\n", b, a);
	}
}