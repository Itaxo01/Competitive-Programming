#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
using namespace std;

void work(){
	int a, b, c; cin>>a>>b>>c;
	int ans = (ceil((double)(abs(b))/(double)(abs(c))));
	if(ans > a) cout<<"-1\n";
	else cout<<ans<<"\n";
}


signed main(){
	int tt; cin>>tt;
	while(tt--)
		work();
	return 0;
}