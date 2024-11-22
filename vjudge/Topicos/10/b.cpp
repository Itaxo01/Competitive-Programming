#include <bits/stdc++.h>
using namespace std;
int l = 1e9;


int phi(int n){
	double res = n;
	for(int p = 2; p*p<=n; p++){
		if(n%p == 0){
			while(n%p == 0){
				n/=p;
			}
			res *= (1.0 - (1.0 / (double)p));
		}
	}
	if(n > 1){
		res -= res/n;
	}
	return (int)res;
}

int main(){
	while(true){
		int a; cin>>a;
		if(!a) break;
		cout<<phi(a)<<endl;
	}
}