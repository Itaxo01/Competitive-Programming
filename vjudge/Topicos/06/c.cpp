#include <bits/stdc++.h>
int a1;
using namespace std;
int solve(int a, int b, int w[], int p[]){
	if(a>1800) a+=200;
    
	int dp[a + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < b ; i++){
        for (int j = a; j >= w[i]; j--){            
			if (dp[j - w[i]] > 0 || j == w[i])
				dp[j] = max(dp[j], dp[j - w[i]] + p[i]);
        }
    }
	
	int maxF = 0;
	if (a1 > 1800 && a1<=2000){
		maxF = *max_element(dp, dp + a1);
		for (int j = 2001; j <= a; ++j)
			maxF = max(maxF, dp[j]);
    }else maxF = *max_element(dp, dp + a + 1);
	
    return maxF;
}

int main(){
	int b;
	while(cin>>a1>>b){
		int p[b];
		int w[b];
		for(int i = 0; i<b; i++){
			cin>>w[i]>>p[i];
		}
		cout<<solve(a1, b, w, p)<<endl;
	}
}
