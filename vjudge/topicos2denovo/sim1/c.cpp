#include <bits/stdc++.h>
#define ll long long
using namespace std;


int di[4] = {1, 1, -1, -1};
int dj[4] = {1, -1, 1, -1};

int n, m;

bool valid(int i, int j){
	return (i>=0 && i<n && j>=0 && j<m);
}

ll simulate(int i, int j, vector<vector<int>> &v){
	ll res = v[i][j];
	int ni = i, nj = j;
	for(int k = 0; k<4; k++){
		while(valid(i+di[k], j+dj[k])) {
			i += di[k], j+=dj[k]; 
			res+=v[i][j];
		}
		i = ni, j = nj;
	}
	return res;
}

int main(){
	int tt; cin>>tt;
	while(tt--){
		cin>>n>>m;
		vector<vector<int>> v(n, vector<int>(m));

		for(auto &vi: v){
			for(auto &e: vi) cin>>e;
		}
		ll res = 0;
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				res = max(res, simulate(i, j, v));
			}
		}
		cout<<res<<endl;


	}
}