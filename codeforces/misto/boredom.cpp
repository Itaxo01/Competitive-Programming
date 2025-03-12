#include <bits/stdc++.h>
#define int long long
#define maxValue 
using namespace std;



signed main(){
	int a; cin>>a;
	map<int, int> m;

	int maior = 0;
	for(int i = 0; i<a; i++){
		int b; cin>>b;
		m[b]++;
		maior = max(maior, b);
	}

	vector<int> dp(maior+1, 0);
	dp[1] = m[1];
	for(int i = 2; i<=maior; i++){
		dp[i] = max(dp[i-1], dp[i-2] + m[i]*i);
	}
	cout<<dp[maior]<<endl;
}