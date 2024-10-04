#include <bits/stdc++.h>

using namespace std;
int main(){

	int a, b, c;cin>>a>>b>>c;
	int primeiro = 0;
	int ultimo = 0;
	for(int i = b; i<=c; i++){
		int s = i;
		int soma = 0;
	    while(s>0){
	        soma += (s%10);
	        s = s/10;
	    }
		if(soma==a){
			if(!primeiro) primeiro = i;
			ultimo = i;
		}
	}
	cout<<primeiro<<endl<<ultimo<<endl;

	return 0;
}