#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n; cin>>n;
	vector<ll> v(n);
	ll soma = -1, soma1 = -1;
	ll odds = 0;
	deque<ll> impares;
	deque<ll> impares1;
	for(ll i = 0; i<n; i++){
		ll c; cin>>c; v[i] = c;
		if(c%2 == 1){
			impares.push_back(i);
			impares1.push_back(i);
			odds++;
			}
	}
	ll e, d; cin>>e>>d;

	if(odds%2==0){
		soma = 0;
		impares.push_front(impares[0]);
		for(int i = 0; i<odds; i+=2){
			ll next_d = ((i+1)%odds+odds)%odds;
			
			ll nd = impares[next_d];
			ll ni = impares[i];

			ll costij_d = (nd-ni)*d;
			ll costji_e = (nd-ni)*e;

			ll costij_e = (n-nd+ni)*e;
			ll costji_d = (n-nd+ni)*d;
			
			ll cost_a, cost_b;

			if(costij_d<costji_e) cost_a = costij_d;
			else cost_a = costji_e;

			if(costij_e<costji_d) cost_b = costij_e;
			else cost_b = costji_d;

			if(cost_a<cost_b){
				soma+=cost_a;
			
			}else{
				soma+=cost_b;
			}
		}
		soma1 = 0;

		for(int i = 1; i<=odds; i+=2){
			ll next_d = i+1;
			
			ll nd = impares1[next_d];
			ll ni = impares1[i];

			ll costij_d = (n-max(nd, ni)+min(nd, ni))*d;
			ll costji_e = (n-max(nd, ni)+min(nd, ni))*e;
			
			ll costij_e = abs((nd-ni))*e;
			ll costji_d = abs((nd-ni))*d;
			
			ll cost_a, cost_b;
			if(costij_e<0 || costji_d<0) cout<<nd<<" "<<ni<<endl;

			if(costij_d<costji_e) cost_a = costij_d;
			else cost_a = costji_e;

			if(costij_e<costji_d) cost_b = costij_e;
			else cost_b = costji_d;


			
			if(cost_a<cost_b){
				soma1+=cost_a;
			
			}else{
				soma1+=cost_b;
			}
		}
	}
	cout<<soma<<" "<<soma1<<endl;
	cout<<min(soma, soma1)<<endl;
}
