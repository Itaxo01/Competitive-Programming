#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	while(n--){
		int a; cin>>a;
		int b[a];
		int maior = 0;
		int menor = INT_MAX;
		for(int i = 0; i<a; i++){
			cin>>b[i];
			maior = max(maior, b[i]);
			menor = min(menor, b[i]);
		}
		cout<<(a-1)*(maior-menor)<<endl;

	}
}