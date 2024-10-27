#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	vector<pair<int, int>> v(n);
	for(int i = 0; i<n; i++){
		cin>>v[i].first>>v[i].second;
	}
	bitset<10001> bs;
	bs.reset();

	sort(v.rbegin(), v.rend());
	int soma = 0;
	for(auto e:v){
		int k = e.second;
		while(k>0 && bs.test(k)) k--;
		if(k<=0) continue;
		// cout<<k<<endl;
		bs.set(k);
		soma+=e.first;
	}
	cout<<soma<<endl;
}