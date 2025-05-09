#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b; cin>>a>>b;
	vector<vector<int>> v(a);
	for(int i = 0; i<a-1; i++){
		int c, d; cin>>c>>d;
		v[c].push_back(d);
		v[d].push_back(c);
	}
	int count = 0;
	for(int i = 0; i<a; i++){
		if(v[i].size() == 1) count++;
	}
	int res = 2*(b/count) + (b % count >= 1) + (b % count >=2);
	cout<<res<<endl;
}