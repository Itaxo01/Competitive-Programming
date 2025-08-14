#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
using namespace std;

const int M = 1e9 + 7;

int mod(int a) {
    return (a % M + M) % M;
}

int K, L, T;
vector<vector<int>> v;
vector<int> p;

vector<vector<int>> dp;
vector<vector<int>> pfx;
int solve(int i, int k){
	if(dp[i][k] != -1) return dp[i][k];
	if(i == T-1) return 1;
	
	dp[i][k] = 0;

	if(pfx[i][0] == -1){
		pfx[i][0] = solve(i+1, 0);
		for(int next_k = 1; next_k < K; next_k++){
			pfx[i][next_k] = mod(solve(i+1, next_k) + pfx[i][next_k-1]);
		}
	}
	
	int l = distance(v[k].begin(), lower_bound(all(v[k]), p[i] - L));
	int r = distance(v[k].begin(), upper_bound(all(v[k]), p[i] + L));
	if(l < r){
		dp[i][k] = mod(dp[i][k] + pfx[i][r-1] - (l > 0 ? pfx[i][l-1] : 0));
	}
	// for(int next_k = l; next_k < r; next_k++){
	// 	dp[i][k] = mod(dp[i][k] + solve(i+1, next_k));
	// }
	return dp[i][k];
}

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>K>>L;
	v.resize(K, vector<int>(K));
	for(auto &k: v){
		for(auto &e: k) cin>>e;
	}
	cin>>T;
	p.resize(T);
	for(int &e: p) cin>>e;
	
	pfx.assign(T, vector<int>(K, -1));
	dp.assign(T+1, vector<int>(K+1, -1));

	int res = 0;
	for(int k = 0; k<K; k++){
		res = mod(res + solve(0, k));
	}
	cout<<res<<endl;
	
}