#include <bits/stdc++.h>
using namespace std;
#define ll long double

struct Line {
  mutable ll k, m, p;
  bool operator<(const Line& o) const { return k < o.k; }
  bool operator<(ll x) const { return p < x; }
};

const ll inf = 1/.0;
struct LineContainer : multiset<Line, less<>> {
  // (for doubles, use inf = 1/.0, div(a,b) = a/b)
  ll div(ll a, ll b) { // floored division
    return a / b ;}//- ((a ^ b) < 0 && a % b); }
  bool isect(iterator x, iterator y) {
    if (y == end()) return x->p = inf, 0;
    if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
    else x->p = div(y->m - x->m, x->k - y->k);
    return x->p >= y->p;
  }
  void add(ll k, ll m) {
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p)
      isect(x, erase(y));
  }
  ll query(ll x) {
    assert(!empty());
    auto l = *lower_bound(x);
    return l.k * x + l.m;
  }
};

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	LineContainer minX, maxX, minY, maxY;

	int n; cin>>n;
	for(int i =0 ; i<n; i++){
		int x, y, vx, vy; cin>>x>>y>>vx>>vy;
		minX.add(-vx, -x);
		maxX.add(vx, x);
		minY.add(-vy, -y);
		maxY.add(vy, y);
	}
	set<ll> points;
	for(auto k: minX) points.insert(k.p);
	for(auto k: minY) points.insert(k.p);
	for(auto k: maxX) points.insert(k.p);
	for(auto k: maxY) points.insert(k.p);
	points.insert(0);
	ll menor = LLONG_MAX;
	for(auto e: points) {
		if(e < 0) continue;
		// if(e == inf || e == -inf) continue;
		ll area = (maxX.query(e) + minX.query(e)) 
					* (maxY.query(e) + minY.query(e));
		menor = min(menor, area);
	}

	printf("%.15Lf\n", menor);

}