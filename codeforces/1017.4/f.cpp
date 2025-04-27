#include <bits/stdc++.h>
#define int long long
using namespace std;

void work(){
	int n, m, k; cin>>n>>m>>k;
	vector<vector<int>> v(n, vector<int>(m));
	int num = 0, pos = 0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			v[i][j] = num + 1;
			num = (num+1)%k;
		}
		if(v[i][0] == num+1) num = (num+1)%k;
	}

	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(j) cout<<" ";
			cout<<v[i][j];
		} cout<<endl;
	}
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt; cin>>tt;
	while(tt--){
		work();
	}
}