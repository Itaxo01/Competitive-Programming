#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod(ll a, ll b){
	return (a%b+b)%b;
}

int maior(int array[], int i, int j){
	int maior = 0;
	for(int k = i; k<=j; k++){
		if(array[k]>maior) maior = array[k];
	}
	return maior;
}

int gcd(int a, int b){
	if(a < b) return gcd(b,a);
	while(b!=0){
		int aux= b;
		b = a%b;
		a = aux;
	}
	return a;
}

int main(){
	int n; cin>>n;
	vector<int> v(n);
	for(int i = 0; i<n; i++){
		int c; cin>>c; 
		v.push_back(c);
	}
	ll soma = 0;
	ll MOD = 1e9+7;
	for(int i = 0; i<n; i++){
		for(int j = i; j<n; j++){
			// soma+=mod(maior(array, i, j)*pow(gcd(i+1, j+1), 2), MOD);
		}
	}
	cout<<"i"<<endl;
	cout<<soma<<endl;
}