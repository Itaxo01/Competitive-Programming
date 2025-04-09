#include <bits/stdc++.h>
#define int long long
using namespace std;

bool check(int n, int b){
	int res1 = 0;
	int res2 = 0;
	int k = 0;
	while(n){
		res1 = res1*10 + n % b;
		res2 = res2 + (pow(10, k)*(n%b));
		k++;
		n/=b;
	}
	return res1==res2;
}

signed main(){
	int n; cin>>n;
	set<int> bases;
	// Testa primeiro para as bases de tamanho 2, que vão ser do tipo kd + d
	// (33 com 32 = 11, 68 com 4 = 44)
	// uma base d, tal que n = d*k + k, n = k(d+1), n/(d+1) = k
	//
	set<int> divisors;
	int aux = n;
	for(int i = 2; i*i<=n; i++){
		if(aux%i == 0){
			while(aux%i == 0){
				vector<int> temp;
				for(int e: divisors){
					int res = e*i;
					temp.push_back(res);
				}
				aux/=i;
				for(int e: temp) divisors.insert(e);
				divisors.insert(i);
			}
		}
	}
	if(aux > 1){
		vector<int> temp;
		for(int e: divisors){
			temp.push_back(e*aux);
		}
		for(int e: temp) divisors.insert(e);
		divisors.insert(aux);
	}
	for(int d: divisors){ // d-1 pois divisor_d = base_d+1;
		if(d > 2 && check(n, d-1)) bases.insert(d-1);
	}
	
	for(int i = 2; i*i<n; i++){
		if(check(n, i)) bases.insert(i);
	}
	if(bases.empty()) cout<<"*\n";
	else {
		bool first = true;
		for(int e: bases){
			if(!first) cout<<" ";
			first = false;
			cout<<e;
		} cout<<endl;
	}
}