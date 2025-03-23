#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a, int b){
	if(!(a % b)) return b;
	return gcd(b, a%b);
}

// int fast_gcd(int a, int b, int n, vector<int> &v){
// 	if(n == 2) return gcd(v[a], v[b]);
// 	if(n & 1) {
// 		return gcd(fast_gcd(a, n/2, n/2, v), gcd(fast_gcd(n/2, b-1, n/2, v), v[b]))
// 	} else {

// 	}
// }

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a; cin>>a;
	int sum = 0;
	int g = 0;
	map<int, int> m;
	bool zero = false;
	for(int i = 0; i<a; i++){
		int b, c; cin>>b>>c;
		sum += b;
		m[b]++;
		if(!b) zero = true;
		if(!g) g = c;
		else g = gcd(g, c);
	}
	int n = m.size();
	vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
	for(int i = 0; i<=n; i++){
		dp[i][0] = 0;
	}
	bool res = false;
	int i = 1;
	
	if(a == 1){
		goto finnaly;
	} else if(sum == 0){
		res = true;
		goto finnaly;
	}

	for(auto it: m){
		for(int j = 1; j<=sum; j++){
			if(dp[i-1][j] >= 0){
				dp[i][j] = 0;
			} else if(j >= it.first && dp[i][j - it.first] >= 0 &&
					 dp[i][j-it.first] < it.second){
				dp[i][j] = dp[i][j - it.first]+1;
			}
		}
		i++;
	}

	for(int j = 0; j<=(sum+1)/2; j++){
		int other = abs(sum - j);
		int d = abs(other-j);
		if(dp[n][j] >= 0){
			// cout<<j<<" "<<" "<<other<<" "<<d<<" "<<g<<endl;
			if(d % g == 0) {
				if(zero || (other && j)){
					res = true;
					goto finnaly;
				}
			}
		}
	}
	finnaly:
	if(res) cout<<"Y\n";
	else cout<<"N\n";

	

}