#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
	int n; cin>>n;
	vector<pair<int, int>> pos(100005, pair<int, int>(-1, -1));
	vector<int> v(2*n);
	for(int &e: v) cin>>e;
	for(int i = 0; i<2*n; i++){
		if(pos[v[i]].first == -1) pos[v[i]].first = i;
		else pos[v[i]].second = i;
	}


	vector<pair<int, ll>> dp(2*n);

	for(int i = 0; i<2*n; i++){
		// dp[-1] = 0, 0
		if(i) dp[i] = max(dp[i], dp[i-1]);
		if(i >= pos[v[i]].second) continue;
		ll dist = pos[v[i]].second - pos[v[i]].first;

		dp[pos[v[i]].second] = max(dp[pos[v[i]].second], make_pair(dp[i].first+1, dp[i].second - dist));
	}
	cout<<dp[2*n-1].first<<" "<<-dp[2*n-1].second<<endl;
}