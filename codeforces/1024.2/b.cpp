#include <bits/stdc++.h>
#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;


void work(){
	int n; cin>>n;
	// O elemento na posição 1 precisa ser maior que n/2 elementos
	vector<int> v(n);
	for(int i = 0; i<n; i++){
		cin>>v[i];
	}
	int menores = 0, maiores = 0;
	for(int i = 1; i<n; i++){
		if(abs(v[i]) < abs(v[0])) menores++;
		else maiores++;
	}
	if(menores <= n/2) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

}

signed main(){
	fastio
	int tt; cin>>tt;
	while(tt--){
		work();
	}
}