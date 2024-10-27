#include <bits/stdc++.h>
#define int long long
using namespace std;

void work(){
	int a, b, c, d;
	cin>>a>>b>>c>>d;
	long long sum = 0;
	sum = sum + (a-c)*(b-1)+(a-c)*(b) + (b-d);
	cout<<sum<<endl;
}

signed main(){
	int n; cin>>n;
	while(n--) work();
}







