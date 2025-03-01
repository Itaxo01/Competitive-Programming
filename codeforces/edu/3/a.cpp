#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
	int a, b; cin>>a>>b;
	vector<int> v(a);
	for(int i = 0; i<a; i++){
		cin>>v[i];
	}
	sort(v.begin(), v.end(), greater<int>());
	int count = 0;
	int sum = 0;
	int i = 0;
	while(sum < b){
		sum+= v[i];
		i++; count++;
	}
	cout<<count<<endl;
}