#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
	return a[2]*a[1] > b[2]*b[1];
}

int main(){
	int co = 1;
	while(true){
		int n; cin>>n;
		if(!n) break;
		vector<vector<int>> blocos(3*n, vector<int>(3));
		for(int i = 0; i<n; i++){
			int a, b, c; cin>>a>>b>>c;
			blocos.push_back({a, min(b, c), max(b, c)});
			blocos.push_back({b, min(a, c), max(a, c)});
			blocos.push_back({c, min(b, a), max(b, a)});
		}
		sort(blocos.begin(), blocos.end(), cmp);
		int dp[3*n+1];
		memset(dp, 0, sizeof(dp));
		int maior = 0;
		for(int j = 1; j<=3*n; j++){
			dp[j] = blocos[j-1][0];
			for(int i = 1; i<j; i++){
				if(blocos[i-1][1] > blocos[j-1][1] &&
					 blocos[i-1][2] > blocos[j-1][2]){
					dp[j] = max(dp[j], dp[i]+blocos[j-1][0]);
				}
			}
			maior = max(maior, dp[j]);
		}
		// printf("Case %d: maximum height = %d\n", co++, maior);
		cout<<maior<<endl;

	}
}