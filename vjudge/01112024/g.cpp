#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int a, b; cin>>a>>b;
	vector<int> v(a);
	for(int i = 0; i<a; i++){
		cin>>v[i];
	}
	int count = 0;
	sort(v.begin(), v.end());
	for(int i = 0; i<a; i++){
		if(v[i] <= b){
			count++;
			b-=v[i];
		} else break;
	}
	cout<<count<<endl;
}