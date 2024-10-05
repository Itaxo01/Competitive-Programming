#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	while(n--){
		int a; cin>>a;
		int maior = 0;
		int pos = 0;
		int maior_soma = 0;
		for(int i = 0; i<a; i++){
			int b; cin>>b;
			if(b>maior){
				maior = b;
				maior_soma = b+1+(i)/2+(a-(i+1))/2;
			}else if(b==maior){
				maior_soma = max(maior_soma, b+1+(i)/2+(a-(i+1))/2);
			}
		}
		cout<<maior_soma<<endl;
	}
}