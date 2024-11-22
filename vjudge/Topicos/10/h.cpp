#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<ll, ll> dp;

void catalan(){
	dp[0] = dp[1] = 1;	
	for (int i = 2; i <= 20; i++) {
		dp[i] = 0;
		for (int j = 0; j < i; j++)
			dp[i] += dp[j] * dp[i - j - 1];
	}

}


int main(){
	ll a;
	catalan();
	while(cin>>a){
		for(int i = 1; i<20; i++){
			if(dp[i] == a){
				cout<<i<<endl;
				break;
			}
		}
	}
}