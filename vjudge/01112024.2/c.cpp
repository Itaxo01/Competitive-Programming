#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b; cin>>a>>b;
	int ar[a];
	for(int i = 0; i<a; i++){
		cin>>ar[i];
	}
	int sum = 0;
	int menor = INT_MAX;
	int maior = 0;
	int m1, m2;
	for(int i = 0; i<a; i++){
		if(i<b) sum+=ar[i];
		else{
			if(sum>maior){
				maior = sum;
				m1 = i-b;
			}
			if(sum<menor){
				menor = sum;
				m2 = i-b;
			}
			sum-=ar[i-b];
			sum+=ar[i];
		}
	}
	if(sum>maior){
		maior = sum;
		m1 = a-b;
	}
	if(sum<menor){
		menor = sum;
		m2 = a-b;
	}
	cout<<m2+1<<" "<<m1+1<<endl;
	
}