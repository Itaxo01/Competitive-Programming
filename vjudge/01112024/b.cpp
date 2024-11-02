#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int a, b; cin>>a>>b;
	if(a < b) swap(a, b);
	int c = pow(a, 2) - pow(b, 2);
	int d = pow(a, 2) + pow(b, 2);
	int e = 2*a*b;
	printf("%ld %ld %ld\n", c, e, d);
}