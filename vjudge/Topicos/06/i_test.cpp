#include <bits/stdc++.h>
using namespace std;
int solve(int a, int b, int w[]){
	
	int dp[20001];
	for(int i = 0; i<20001; i++){
		dp[i] = 20000;
	}
	dp[0] = 0;
    for (int i = 0; i < b ; i++){
        for (int j = 20000; j >= w[i]; j--){            
			dp[j] = min(dp[j], dp[j - w[i]] + 1);
        }
    }
	
	int i;
	for(i = a; dp[i] == 20000; i++);
	printf("%d %d\n", i, dp[i]);
    return dp[a];
}

int main(){
	int n; cin>>n;
	while(n--){
		int a, b;
		cin>>a>>b;
		int w[b];
		for(int i = 0; i<b; i++){
			cin>>w[i];
		}
		solve(a, b, w);
	}
}
