#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int n; cin>>n;
	int a = floor(sqrt(n));
	int menor = INT_MAX;
	for(int i = 1; i<=a; i++){
		if(n%i) continue;
		for(int j = 1; j<=a; j++){
			if(n%(i*j)) continue;
			int k = n/(i*j);
			menor = min(menor, 2*(i*j+i*k+j*k));
		}
	}
	cout<<menor<<endl;
}