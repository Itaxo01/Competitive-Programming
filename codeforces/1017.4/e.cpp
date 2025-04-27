#include <bits/stdc++.h>
#define int long long
using namespace std;


void work(){
	int n; cin>>n;
	vector<int> v(n);
	vector<int> b_freq(33, 0);
	vector<int> pot(33);
	pot[0] = 1;
	for(int i = 1; i<33; i++){
		pot[i] = pot[i-1]*2;
	}	
	int max_sum = 0;
	for(int i = 0; i<n; i++){
		cin>>v[i];
		int aux = v[i];
		int pos = 0;
		max_sum += v[i];
		while(aux){
			b_freq[pos] += (aux & 1);
			aux >>=1;
			pos++;
		}
	}
	vector<int> b_values(33);
	for(int i = 0; i<33; i++){
		b_values[i] = (n-b_freq[i])*pot[i] - b_freq[i]*pot[i];
	}
	int maior = 0;
	for(int i = 0; i<n; i++){
		int sum = 0;
		int aux = v[i];
		int pos = 0;
		while(aux){
			sum += (aux & 1 ? b_values[pos] : 0);
			aux >>=1;
			pos++;
		}
		maior = max(maior, max_sum + sum);
	}
	cout<<maior<<endl;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt; cin>>tt;
	while(tt--){
		work();
	}
}