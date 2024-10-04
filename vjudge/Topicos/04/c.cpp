#include <bits/stdc++.h>

using namespace std;

int main(){
	while(true){
		int a, b; cin>>a>>b;
		if(!a && !b) break;
		vector<vector<int>> v(a, vector<int>(b));
		for(int i = 0; i<a; i++){
			for(int j = 0; j<b; j++){
				cin>>v[i][j];
			}
		}
		int n; cin>>n;
		for(int i = 0; i<n; i++){
			int l, r; cin>>l>>r;
			int maior_d = 0;
			for(int j = 0; j<a; j++){
				int d = 0;
				auto it = lower_bound(v[j].begin(), v[j].end(), l);
				if(*it>r || it == v[j].end()) continue;

				int pos_j = distance(v[j].begin(), it), pos_i = j;
				while(v[pos_i][pos_j]>=l && v[pos_i][pos_j]<=r){
					d++; pos_i++; pos_j++;
					if(pos_i>=a || pos_j>=b) break;
				}
				if(d>maior_d) maior_d = d;
			}
			cout<<maior_d<<endl;
		}
		cout<<"-"<<endl;
	}
}