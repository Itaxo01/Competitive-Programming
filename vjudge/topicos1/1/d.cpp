#include <bits/stdc++.h>
#define int long long
using namespace std;

void factorize(int a, map<int, int> &factors){
	for(int i = 2; i*i<=a; i++){
		while(a%i == 0){
			factors[i]++;
			a/=i;
		}
	}
	if(a > 1) factors[a]++;
}

signed main(){
	int a; cin>>a;
	map<int, int> factors;
	factorize(a, factors);

	bool res = false;
	for(auto e: factors){
		if(e.second & 1) res = true;
		// cout<<e.first<<": "<<e.second<<endl;
	}
	
	if(res) cout<<"Y\n";
	else cout<<"N\n";
	
}