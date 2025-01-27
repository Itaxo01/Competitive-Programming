#include <bits/stdc++.h>
#define int long long
using namespace std;

void work(){
	int n; cin>>n;
	// -1, -3, 0, -4, 1, 7, 13, 5, 14, 24, 35, 47, 50, 64, 79, 63
	// formula pa 1 - n, menos 2x a soma das potências de 2 até n, que é o 2*(2^(msb(n)+1)-1)
	int sum = (1+n)*n/2;
	int count = 0;
	while(n){
		count++; n>>=1;
	}
	int sum2 = 2*((1<<count)-1);
	cout<<sum-sum2<<endl;
}


signed main(){
	int tt; cin>>tt;
	while(tt--){
		work();
	}
}