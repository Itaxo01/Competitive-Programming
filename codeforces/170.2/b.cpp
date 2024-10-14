#include <bits/stdc++.h>
#define ll long long
#define m 1000000007
using namespace std;

ll fastpow(int n, int k){
	if(k <= 0) return 1;
	if(k == 1) return n;
	ll x = fastpow(n, k/2);
	if(k & 1) return (((x*x)%m)*n)%m;
	return (x*x)%m;

}

int main(){

	int N; cin>>N;
	for(int i = 0; i<N; i++){
		int a; cin>>a;
	}
	for(int i = 0; i<N; i++){
		int a; cin>>a;
		cout<<fastpow(2, a)<<endl;
	}
}