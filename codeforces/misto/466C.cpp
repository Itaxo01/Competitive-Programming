#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
	int a; cin>>a;
	int sum = 0;
	vector<int> v(a);
	for(int i = 0; i<a; i++){
		cin>>v[i];
		sum+=v[i];
	}
	if(sum % 3 != 0 || a < 3) cout<<"0\n";
	else{
	}

}