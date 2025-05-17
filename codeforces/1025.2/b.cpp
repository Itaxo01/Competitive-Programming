#include <bits/stdc++.h>
#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int x_, y_, x, y;
int remove(int i, int j){
	int y_aux = (y - y_ + 1), x_aux = (x - x_ + 1);
	int k1 = y_aux*(j - x_), k2 = y_aux*(x - j);
	int k3 = x_aux*(i - y_), k4 = x_aux*(y - i);

	int k = max({k1, k2, k3, k4});
	if(k == k1){
		x_ = j;
	} else if(k == k2){
		x = j;
	} else if(k == k3){
		y_ = i;
	} else if(k == k4){
		y = i;
	}
	return k;
}

void work(){
	int c, d; cin>>y>>x>>c>>d;
	x_ = 1, y_ = 1;
	int size = x*y;
	int res = 0;
	while(size > 1){
		res++;
		size -= (remove(c, d));
		c = (y_+y+1)/2;
		d = (x_+x+1)/2;
	}
	cout<<res<<endl;
}

signed main(){
	fastio
	int tt; cin>>tt;
	while(tt--){
		work();
	}
}