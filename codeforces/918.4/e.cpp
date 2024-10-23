#include <bits/stdc++.h>
#define int long long
using namespace std;


void work(){
	int a; cin>>a;
	bool res = false;
	int sum = 0;
	map<int, int> m;
	for(int i = 0; i<a; i++){
		int c; cin>>c;
		if(i & 1) sum+=c;
		else sum-=c;
		if(sum == 0) res = true;
		
		if(m.find(sum) != m.end()) res = true;
		else m[sum]++; 
	}
	
	if(res) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}

signed main(){
	int n; cin>>n;
	while(n--){
		work();
	}
}