#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
	int a; cin>>a;
	vector<int> v(a);
	
	int sum = 0;
	for(int i = 0; i<a; i++){
		cin>>v[i];
		sum += v[i];
	}

	int l = floor(sum / (double)a);
	int u = ceil(sum / (double)a);
	int u_count = sum - l*a;
	// divide for exemple 50 over 6, it will be 48 + 2, or 8 x 6 + 2 x 7. 
	// l is for the 6, u is for the 7. I also want to know how many of each
	sort(v.rbegin(), v.rend());

	int count = 0;
	int i = 0;
	while(v[i] > )

	cout<<count/2<<endl;
}