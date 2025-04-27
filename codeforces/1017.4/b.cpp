#include <bits/stdc++.h>
using namespace std;

void work(){
	int a, b, c, d; cin>>a>>b>>c>>d;
	int sub = a-b;
	int aux = c;
	c = min(0, c+sub);
	sub = sub - (abs(aux-c));
	d -= sub;
	cout<<c<<" "<<d<<endl;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt; cin>>tt;
	while(tt--){
		work();
	}
}