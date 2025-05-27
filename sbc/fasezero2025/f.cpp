#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n; cin>>n;
	vector<int> v(n);
	for(int i = 0; i<n; i++){
		cin>>v[i];
	}

	vector<vector<ll>> dp(5, vector<ll>(8001, 0));
	dp[0][4000] = 1;

	for(int k: v){
		for(int i = 4; i>=1; i--){
			for(int s = 0; s<=8000; s++){
				if(!dp[i-1][s]) continue;
				int sr = k+s;
				if(0 <= sr && sr <= 8000){
					dp[i][sr] += dp[i-1][s];
				}
			}
		}
	}

	int nq; cin>>nq;
	for(int i = 0; i<nq; i++){
		int q; cin>>q;
		q += 4000;
		if(0 <= q && q <= 8000)
			cout<<dp[4][q]<<endl;
		else cout<<0<<endl;
	}
    return 0;
}
