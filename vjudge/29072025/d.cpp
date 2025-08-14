#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
#define ll long long




int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, d; cin>>n>>d;

	vector<pair<int, int>> v(n);
	for(auto &[a, b]: v) cin>>a>>b;

	sort(all(v));
	vector<ll> dp(n+1);
	
	ll maior = 0;
	int j = 0; // i mantém o ponto atual, j mantém o último ponto que não conflita
	for(int i = 0; i<n; i++){
		while(v[i].first-v[j].first >= d) maior = max(maior, dp[j]), j++;
		dp[i] = maior + v[i].second; 
	}

	cout<<*max_element(all(dp))<<endl;



}