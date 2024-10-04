#include <bits/stdc++.h>

using namespace std;

int energy_to_bill(int n){
	int total = 0;
	if(n>1000000){
		total+= 7*(n-1000000);
		n = 1000000;
	}
	if(n>10000){
		total += 5*(n-10000);
		n = 10000;
	}
	if(n>100){
		total += 3*(n-100);
		n = 100;
	}
	total+= 2*n;
	return total;
}

int bill_to_energy(int n){
	int total = 0;
	if(n>4979900){
		total+= (n-4979900)/7;
		n = 4979900;
	}
	if(n>29900){
		total += (n-29900)/5;
		n = 29900;
	}
	if(n>200){
		total += (n-200)/3;
		n = 200;
	}
	total += n/2;
	return total;
}


int main(){
	int a, b;
	while(cin>>a>>b){
		if(!a && !b) break;
		int total = bill_to_energy(a);
		int inicio = 0;
		int fim = (total/2)+1;


		while(inicio<fim){
			int meio = (inicio+fim)/2;
			int meio1 = energy_to_bill(meio);
			int meio2 = energy_to_bill(total-meio);
			int meio3 = energy_to_bill(meio+(total-meio));
			
			if(meio3==a && abs(meio1-meio2)==b){
				cout<<min(meio1, meio2)<<endl;
				break;
			}
			else if(abs(meio1-meio2)>b){
				inicio = meio+1;
			}
			else{
				fim = meio;
			}
		}
	}
}