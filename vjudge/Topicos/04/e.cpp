#include <bits/stdc++.h>

using namespace std;

bool test(vector<int> &v, int m, int k){
	int k1 = 1;
	int atual = 0;
	for(int i = 0; i<v.size(); i++){
		if(v[i]>m) return false;
		if(atual+v[i]>m){
			atual = 0;
			k1++;
			if(k1>k) return false;
		}
		atual+=v[i];
	}
	return true;
}

int main(){
	int a, b;
	while(cin>>a>>b){
		vector<int> v(a);
		int soma = 0;
		for(int i = 0; i<a; i++){
			cin>>v[i];
			soma+=v[i];
		}
		int l = 0;
		int r = soma;
		while(l<r){
			int m = (l+r)/2;
			if(test(v, m, b)){
				r = m;
			}else{
				l = m+1;
			}
		}
		cout<<l<<endl;

	}
}