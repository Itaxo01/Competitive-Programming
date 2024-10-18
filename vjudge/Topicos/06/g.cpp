#include <bits/stdc++.h>
using namespace std;

string lcs(string &s, string &t) {
    int n = s.size(), m = t.size();
    int dp[n+1][m+1];
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    memset(dp[0], 0, sizeof(int)*(m+1));
        
    for (int i = 1; i <= n; ++i) {
        memset(dp[i], 0, sizeof(int)*(m+1));
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string lcs_str;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            lcs_str.push_back(s[i - 1]);
            --i;
            --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    reverse(lcs_str.begin(), lcs_str.end());
    return lcs_str;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin>>s>>t;
    cout<<lcs(s, t)<<endl;
}