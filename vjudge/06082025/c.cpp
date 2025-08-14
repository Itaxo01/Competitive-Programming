#include <bits/stdc++.h>
#define ll long long
using namespace std;


inline ll sum(int l, int r, vector<ll> &p){
	return p[r] - (l ? p[l-1] : 0);
}

int main(){
	int tt; cin>>tt;
	
	while(tt--){
		int n; cin>>n;;
		vector<ll> v(n);
		for(ll &e: v) cin>>e;
		// para cada posição estou interessado em saber quantos ranges incluem essa posição e possuem soma menor que 2x essa posição.

		vector<ll> p(n);
		for(int i = 0; i<n; i++){
			p[i] = v[i];
			if(i) p[i] += p[i-1];
		}


		ll res = 0;
		for(int i = 0; i<n; i++){
			// para cada som, preciso saber quanto ele contribui

			// a ideia é a seguinte: Busca binária em p para saber qual a posição mais a esquerda que posso ir. Sendo essa posição L, todos os ranges de L até i são válidos. Agora, começo com um R em i e vou avançando com o L até i e vou expandindo o R para a direita. A cada novo R alcançável, somo R-L+1.

			// Essa ideia passou pela minha cabeça, mas em teoria seria quadrática, porém como o editorial traz ela de fato não é, visto que o range considerado não pode ser máximo para todos os números
			// o range de um número ser máximo implica em outros serem mínimos.
			int L, R = i;
			int l = 0, r = i;
			while(l < r){
				int m = l + (r-l)/2;
				// estou interessado na soma do range(m, i)
				ll s = sum(m, i, p);
				if(2*v[i] > s){
					// posso "aumentar" o range, nesse caso, diminuir o r
					r = m;
				} else {
					l = m+1;
				}
			}

			L = l;
			while(L <= i){
				while(R < n && sum(L, R, p) < 2*v[i]) R++;
				res += R-i;

				L++;
			}

		}
		cout<<res<<endl;

	}
}