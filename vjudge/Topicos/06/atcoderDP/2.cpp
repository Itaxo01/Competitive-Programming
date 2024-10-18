#include <bits/stdc++.h>

using namespace std;

void solve(int n, int k, int a[]){
	
	int dp[n];
	for(int i = 0; i<n; i++) dp[i] = INT_MAX;
	dp[0] = 0;
	dp[1] = abs(a[1]-a[0]);
	for(int i = 2; i<n; i++){
		for(int j = 1; j<=k && j<=i; j++){
			dp[i] = min(dp[i], dp[i-j]+abs(a[i]-a[i-j]));
		
		}
	}
	cout<<dp[n-1]<<endl;
}

int main(){
	int n, k;
	cin>>n>>k;
	int a[n];
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	solve(n, k, a);
}