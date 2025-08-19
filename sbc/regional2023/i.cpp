#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n; cin>>n;
	// essencialmente da para pensar nisso como a quantidade de substrings de xor 1
	

	vector<ll> d(2);
	d[0] = 1;
	int acc = 0;
	ll res = 0;
	for(int i = 0; i<n; i++){
		int k; cin>>k;
		acc^=k;
		res += d[acc^1];
		d[acc]++;
	}
	cout<<res<<endl;
}