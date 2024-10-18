#include <bits/stdc++.h>

using namespace std;

int a1 = 0;
int b1 = 0;
int c1 = 0;
int a[100005]; 
int b[100005]; 
int c[100005];

int solve(int i, int total, int dp[]){

	dp[i] = max({solve(i+1, total+a[i]),
				 solve(i+1, total+b[i]),
				 solve(i+1, total+c[i])});
	return dp[i];
}


int main(){
	int n; cin>>n;
	for(int i = 0; i<n; i++) cin>>a[i];
	for(int i = 0; i<n; i++) cin>>b[i];
	for(int i = 0; i<n; i++) cin>>c[i];
	a1 = 0; b1 = 0; c1 = 0;

	

	
}