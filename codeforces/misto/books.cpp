#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int a, b; cin>>a>>b;
	vector<int> aux(a);
	for(int i = 0; i<a; i++){
		cin>>aux[i];
	}

	vector<int> v(a);
	v[0] = aux[a-1];
	for(int i = 1; i<a; i++){
		v[i] = v[i-1] + aux[(a-1)-i];
	}

	int maior = 0;
	for(int i = 0; i<a; i++){
		int d = distance(v.begin()+i, upper_bound(v.begin(), v.end(), v[i]+(b-aux[(a-1)-i])));
		maior = max(maior, d);
	}
	cout<<maior<<endl;
}