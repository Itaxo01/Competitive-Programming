#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int a; cin>>a;
	// 0 = 1, 1 = 1, 2 = 2;
	int b = 1;
	int c = 0;
	int d = 0;
	for(int i = 0; i<a; i++){
		d = b;
		b = b+c;
		c = d;
	}
	cout<<b<<endl;
}