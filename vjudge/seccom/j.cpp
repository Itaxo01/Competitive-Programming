#include <bits/stdc++.h>
#define int long long
using namespace std;

int max(vector<int> &v){
	int maior = 0;
	for(int e:v) maior = max(maior, e);
	return maior;
}

signed main(){
	while(true){
		int n; cin>>n;
		if(!n) break;
		vector<vector<int>> blocos(n, vector<int>(3));
		for(int i = 0; i<n; i++){
			for(int j = 0; j<3; j++){
				cin>>blocos[i][j];
			}
		}
		pair<int, int> dp[n+1];
		int init = max(blocos[0]);
		for(int i = 0; i<=n; i++){
			dp[i].first = init;
			dp[i].second = 0;
		}
		for (int i = 1; i < n ; i++){
			pair<bool, int> res = menor(blocos[i], blocos[dp[i-1].second]);
			if(menor.first){
				if(dp[i].first < dp[i-1].first+res.second){
					dp[i].second = i;
					dp[i].first = dp[i-1].first+res.second;
				}
			} else{
				if(dp[i].first < dp[i-1].first){
					dp[i] = dp[i-1];
				}
			}
		}
		cout<<dp[n].first<<endl;

	}
}