#include <bits/stdc++.h>
// #define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define yes {cout<<"YES"<<endl; return ;}
#define no {cout<<"NO"<<endl; return ;}
using namespace std;

tuple<int, int, int> gcd(int a, int b) {
  if(b == 0) return make_tuple(a, 1, 0);
  int q, w, e;
  tie(q, w, e) = gcd(b, a % b);
  return make_tuple(q, e, w - e * (a / b));
}


void work(){
	int n; cin>>n;
	vector<int> v(n);
	for(auto &e: v) cin>>e;
	// v[0] = 1x + ny
	// v[1] = 2x + (n-1)y
	// ..
	// v[1] - v[0] = x - y
	// x = v1 - v0 + y
	// 2v[0] = v1 + (n+1)y
	// (2v[0] - v1)/(n+1) = y
	int y = (2*v[0]-v[1])/(n+1);
	int x = v[1] - v[0] + y;
	if(x < 0 || y < 0) no
	for(int i = 1; i<=n; i++){
		int r = n-i+1;
		if(x*i + y*r != v[i-1]) no
	}
	yes
}

signed main(){
	fastio
	int tt; cin>>tt;
	while(tt--){
		work();
	}
}