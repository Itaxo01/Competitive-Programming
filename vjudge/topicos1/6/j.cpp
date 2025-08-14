#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> m;
vector<int> p9;
void permutate(vector<int> &v, int i, int hash, int val){
	if(i >= 8) {
		m[hash]+=val;
		return;
	}
	for(int j = 0; j<=v[i]; j++){
		permutate(v, i+1, hash+j*p9[i], val);
	}
}

signed main(){
	int n, k; cin>>n>>k;
	p9.resize(8);
	p9[0] = 1;
	for(int i = 1; i<8; i++) p9[i] = p9[i-1]*9;
	map<int, vector<int>> labels;
	int sz = 1;
	for(int i = 0; i<n; i++){
		char c; cin>>c;
		int r; cin>>r;
		if(c == 'D'){
			permutate(labels[r], 0, 0, -1);
			labels[r].clear();
		} else{
			vector<int> v(8);
			for(int i = 0; i<r; i++){
				int t; cin>>t;
				v[t-1]++;
			}
			if(c == 'C') {
				labels[sz++] = v;
				permutate(v, 0, 0, 1);
			} else {
				int hash = 0;
				for(int i = 0; i<k; i++){
					hash += v[i]*p9[i];
				}
				cout<<m[hash]<<endl;
			}
		}
	}
}