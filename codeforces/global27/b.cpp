#include <bits/stdc++.h>
using namespace std;

void work() {
    int a; cin>>a;
    string dp[2][11];
    for(int j = 0; j < 11; j++){
        dp[0][j] = "0";
    }
    dp[0][0] = "";

    for(int i = 1; i <= a; i++){
        int current = i % 2;
        int prev = 1 - current;

        for(int j = 0; j < 11; j++){
            dp[current][j] = "0";
        }

        for(int j = 0; j < 11; j++){
            if(dp[prev][j] != "0"){
                int j3, j6;
                if(i & 1){
                    j3 = (j + 3) % 11;
                    j6 = (j + 6) % 11;
                }else{
                    j3 = (j + 8) % 11; 
                    j6 = (j + 5) % 11; 
                }
                string dp3 = dp[prev][j] + '3';
                string dp6 = dp[prev][j] + '6';

                if (i != a) {
                    if (dp[current][j3] == "0" || dp[current][j3] > dp3) {
                        dp[current][j3] = dp3;
                    }
                }
                if (dp[current][j6] == "0" || dp[current][j6] > dp6) {
                    dp[current][j6] = dp6;
                }
            }
        }
    }

    if (dp[a % 2][0] != "0") {
        cout << dp[a % 2][0] << endl;
    } else {
        cout << "-1\n";
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    while (n--) {
        work();
    }
    return 0;
}
