#pragma optimize ("O3")
#define ll long long
#include <bits/stdc++.h>
using namespace std;

bool possible(ll a, ll b, ll c, ll p, ll h){
	if((p+b)*c*a > p) return true;
	else if(p && a) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	ll n, p, h; cin>>n>>p>>h;

	ll attack = 0, sum = 0, multiply = 1;
	vector<ll> s, m;
	for(int i = 0; i<n; i++){
		char c; cin>>c;
		if(c == '!') attack++;
		else {
			ll x; cin>>x;
			if(c == '+') {
				sum= min(sum+x, (ll)(1e9+1));
				s.push_back(x);
			} else {
				if(x > 1){
					multiply = min(multiply*x, (ll)(1e9+1));
					m.push_back(x);
				}
			}
		}
	}
	sort(s.rbegin(), s.rend());
	sort(m.rbegin(), m.rend());
	if(possible(attack, sum, multiply, p, h)){
		// O N é 50, posso computar as combinações de soma, multiply e attack?
		// Novamente, o melhor a se fazer com o deck é somar todos, multiplicar todos, e depois atacar
		// Ele fará isso, a não ser que haja uma forma mais rápida de ganhar com aquele deque.
		if((p+sum)*multiply <= p){
			// edge case onde sum e multiply são inuteis (sum == 0, multiply == 1)
			// A quantidade de ataques será o ceil h/p, e ele precisa ciclar o deck para eventualmente
			// atacar x vezes.
			ll need = ceil(h/(double)p);
			ll rounds = ceil(need/(double)attack)-1;
			ll res = need + (n-attack)*rounds;
			cout<<res<<endl;
		} else {
			ll rounds = 0;
			while(true){
				ll k = p;
				k += sum;
				k *= multiply;
				// cout<<k<<endl;
				if(k*attack < h) {
					p = k;
					h-=k*attack;
				}
				else break; // Significa que no deck atual é possível matar o boss. Preciso descobrir
				// Quantas cartas são necessárias.
				rounds++;
			}
			// cout<<p<<" "<<h<<endl;
			// Agora preciso descobrir quantas cartas ainda são necessárias.
			ll menor = INT_MAX;
			ll n_sum = 0;
			for(int i = 0; i<=n; i++){
				if(i && i <= s.size()) n_sum += s[i-1];
				ll n_mult = 1;
				for(int j = 0; j<=n; j++){
					if(j && j <= m.size()) n_mult = min(n_mult*m[j-1], (ll)(1e9+10));
					for(int t = 1; t <= attack; t++){
						// i = somas, j = mult, t = attack,
						if((p+n_sum)*n_mult*t >= h) {
							// cout<<i<<" "<<j<<" "<<t<<endl;
							menor = min(menor, (ll)(i+j+t));
						}
					}
				}
			}
			cout<<rounds*n+menor<<endl;
		}
	} else cout<<"*"<<endl;
}