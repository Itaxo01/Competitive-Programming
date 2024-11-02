#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int x, y, z; cin>>x>>y>>z;
	if((x < y && abs(y)==y) || (x > y && abs(y)!=y)) cout<<abs(x)<<endl;
	else if ((z < y && abs(y)==y) || (z > y && abs(y)!=y)){
		if ((z > 0 && x > 0) || (z < 0 && x < 0)) cout<<abs(x)<<endl;
		else cout<<abs(x)+2*abs(z)<<endl;
	} else cout<<-1<<endl;

}