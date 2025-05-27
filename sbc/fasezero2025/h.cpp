#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	string b = "";
	int n; cin>>n;
	int n_size = 0;
	while(n){
		b.push_back(n & 1 ? '1' : '0');
		n>>=1; n_size++;
	}

	bool pruned = false;
	for(int left = n_size-1; left>=n_size/2; left--){
	}
}