#include <bits/stdc++.h>
// #define int long long
using namespace std;
// int v[200005];

void work(){
	int a, b; cin>>a>>b;
	// memset(v, 0, sizeof(v));
	
	unordered_map<int, int> v;
	multiset<int> m;
	for(int i = 0; i<b; i++){
		int c, d; cin>>c>>d;
		v[c] += d;
	}
	int sum = 0;
	for(auto e:v){
		m.insert(e.second);
	}
	int i = 0;
	for(auto e = m.rbegin(); e!=m.rend(); e++){
		sum+=(*e);
		// cout<<(*e)<<" ";
		i++;
		if(i==a) break;
	}
	cout<<sum<<endl;
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin>>n;
	while(n--) work();
}