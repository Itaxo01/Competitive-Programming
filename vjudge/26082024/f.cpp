#include <bits/stdc++.h>


using namespace std;
int main(){
	int n; cin>>n;
	int ultimo = n;
	int inicio = 1;
	int distancia = 1;
	bool e_d = true;
	while(n>2){
		if(e_d){
			if(n%2==0) ultimo -= distancia;
		}
		else{
			if(n%2==0) inicio +=distancia;
		}
		distancia*=2;
		n= (n+1)/2;
		e_d=!e_d;
	}
	if(e_d) cout<<inicio<<endl;
	else cout<<ultimo<<endl;
}