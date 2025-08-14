#pragma GCC optimize("O3")

#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
using namespace std;

const int M = 1e9 + 7;

int mod(int a) {
    return (a % M + M) % M;
}

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int K, L;
    cin>>K>>L;
    vector<vector<int>> t(K, vector<int>(K));
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            cin >> t[i][j];
        }
    }

    int n; cin>>n;
    vector<int> p(n - 1);
    for (int &e : p) cin >> e;

	 vector<int> dp(K, 1);
    for (int i = 0; i < n - 1; ++i) {
        vector<int> diff(K + 1, 0);
        for (int k = 0; k < K; ++k) {
            if (dp[k] == 0) continue;

            int l = distance(t[k].begin(), lower_bound(all(t[k]), p[i] - L));
            int r = distance(t[k].begin(), upper_bound(all(t[k]), p[i] + L));
				if (l < r) {
					diff[l] = mod(diff[l] + dp[k]);
					diff[r] = mod(diff[r] - dp[k]);
            }
        }

        vector<int> next_dp(K);
        int s = 0;
        for (int j = 0; j < K; ++j) {
            s = mod(s + diff[j]);
            next_dp[j] = s;
        }
        dp = next_dp;
    }

    int res = 0;
    for (int i = 0; i < K; i++) {
        res = mod(res + dp[i]);
    }
    cout << res << endl;
}