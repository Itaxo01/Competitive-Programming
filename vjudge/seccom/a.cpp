#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int n; cin>>n;
	vector<int> x(n);
	vector<int> y(n);
	
	for(int i = 0; i<n; i++){
		cin>>x[i]>>y[i];
	}

	// |x1*y2 + x2*y3 + x3*y1 - y1*x2 - y2*x3 - y3*x1|
	
	int sum = 0;
	int j = n - 1;
    for (int i = 0; i < n; i++){
        sum += (x[j] + x[i]) * (y[j] - y[i]);
        j = i;
    }
	cout<<abs(sum)<<endl;
}