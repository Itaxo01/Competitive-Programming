#include <bits/stdc++.h>
using namespace std;


void work(){
	int a; cin>>a;
	vector<int> v(a);
	
	for(int i = 0; i<a; i++){
		cin>>v[i];
	}

	// Código burro, com certeza existe uma forma melhor de fazer
	// porém não é necessária;

	int count = 0;
	for(int i = 1; i<=a; i++){
		int pos = distance(v.begin(), find(v.begin(), v.end(), i));
		// navego força bruta até o proximo elemento
		count += abs(i-(pos+1));
		for(int j = pos; j>=i; j--){
			v[j] = v[j-1];
		}
		v[i-1] = i;
	}
	printf("Optimal train swapping takes %d swaps.\n", count);
}

int main(){
	int tt; cin>>tt;
	for(int i = 0; i<tt; i++) work();
}