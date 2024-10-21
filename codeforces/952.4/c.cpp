#include <bits/stdc++.h>
#define int long long
using namespace std;

void work(){
	int a; cin>>a;
	int b[a];
	for(int i = 0; i<a; i++){
		cin>>b[i];
	}
	int maior = 0;
	int soma = 0;
	int count = 0;

	for(int i = 0; i<a; i++){
		if(b[i]>maior){
			soma+=maior;
			maior = b[i];
		} else{
			soma+=b[i];
		}
		if(soma==maior){
			count++;
		}
	}
	cout<<count<<endl;
}

signed main(){
	int n; cin>>n;
	while(n--){
		work();
	}
}