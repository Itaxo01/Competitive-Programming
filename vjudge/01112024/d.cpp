#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int a, b; cin>>a>>b;
	int c = 0;
	if(a & 1 || b & 1) c+=1;
	a>>=1; b>>=1;
	if(a & 1 || b & 1) c+=2;
	a>>=1; b>>=1;
	if(a & 1 || b & 1) c+=4;
	a>>=1; b>>=1;
	cout<<c<<endl;
}