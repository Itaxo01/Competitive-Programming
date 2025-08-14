#include <bits/stdc++.h>
using namespace std;


signed main(){
	int n, k; cin>>n>>k;
	
	map<vector<int>, int> m;

	for(int i = 0; i<n; i++){
		char c; cin>>c;
		int r; cin>>r;
		if(c == 'D'){
		} else{
			vector<int> v(k);
			for(int i = 0; i<r; i++){
				int t; cin>>t;
				v[t-1]++;
				if(c == 'C') m[v]++;
			}
			if(c == 'J') cout<<m[v]<<endl;
		}
	}
}