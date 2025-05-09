#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	vector<string> nomes(n);
	vector<pair<int, int>> v(n);
	for(int i = 0; i<n; i++){
		cin>>nomes[i];
		int a; cin>>a;
		int sum = 10*a;
		vector<int> t(6);
		for(int k = 0; k<6; k++) cin>>t[k];
		sort(t.begin(), t.end());
		for(int k = 1; k<5; k++) sum += t[k];

		v[i] = {sum, -i};
	}
	sort(v.rbegin(), v.rend());

	int c = 0;
	int anterior = v[0].first;
	int diff = 0;
	while(diff < 3){
		if(c < n && anterior != v[c].first) diff = diff + c -diff;
		if(diff >= 3 || c == n) break;
		anterior = v[c].first;
		cout<<nomes[-v[c].second]<<" "<<v[c].first<<endl;
		c++;
	}
}