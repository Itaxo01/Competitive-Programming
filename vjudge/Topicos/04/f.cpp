#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> &v, int k){
	int anterior = 0;
	for(int i = 0; i<v.size(); i++){
		if(v[i]-anterior > k) return false;
		else if(v[i]-anterior == k) k--;
		anterior = v[i];
	}
	return true;
}

int main(){
	int n; cin>>n;
	int c = 1;
	while(n--){
		int a; cin>>a;
		vector<int> v(a);
		for(int i = 0; i<a; i++){
			cin>>v[i];
		}
		sort(v.begin(), v.end());
		int inicio = 0;
		int fim = 1e7;
		while(inicio<fim){
			int meio = (inicio+fim)/2;
			if(check(v, meio)){
				fim = meio;
			}else{
				inicio = meio+1;
			}
		}
		printf("Case %d: %d\n", c++, inicio);

	}
}