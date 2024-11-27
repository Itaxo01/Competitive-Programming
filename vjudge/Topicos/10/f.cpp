#include <bits/stdc++.h>
#define int long long
using namespace std;


int c1, n1, c2, n2;

tuple<int, int, int> gcd(int a, int b){
	if(b == 0) return make_tuple(a, 1, 0);
	int q, w, e;
	tie(q, w, e) = gcd(b, a%b);
	return make_tuple(q, e, w - e*(a/b));
}

int cost(int x, int y){
	return c1*x + c2*y;
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	while(true){
		int a; cin>>a;
		if(!a) break;
		cin>>c1>>n1>>c2>>n2; // n1 = 3, n2 = 4, 3x+4y = a
		int g, x0, y0;
		tie(g, x0, y0) = gcd(n1, n2);
		if(a % g != 0){
			cout<<"failed"<<endl;
			continue;
		}
		x0 *= a/g; 	// x0n1 + y0n2 = 1;
		y0 *= a/g;
		
		int l = ceil(-x0 * g / (long double) n2);
		int r = floor(y0 * g / (long double) n1);
		
		int x = x0 + n2/g * l;
		int y = y0 - n1/g * l;
		int x1 = x0 + n2/g * r;
		int y1 = y0 - n1/g * r;

		if(cost(x1, y1) < cost(x, y)){
			x = x1;
			y = y1;
		}

		if((!x && !y) || x < 0 || y < 0) cout<<"failed"<<endl;
		else cout<<x<<" "<<y<<endl;

	}
}