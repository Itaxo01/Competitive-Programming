#include <bits/stdc++.h>
using namespace std;


signed main(){
	string s; cin>>s;
	int q; cin>>q;
	for(int i = 0; i<q; i++){
		int l, r, k; cin>>l>>r>>k;
		l--; r--;
		int m = r-l+1;
		string n_s = s;
		for(int i = 0; i<m; i++){
			int pos = (i+k)%m;
			s[l+pos] = n_s[l+i];
		}
	}
	cout<<s<<endl;
}