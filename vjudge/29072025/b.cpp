#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

class SegTree{
private:
  int n;
  vector<ll> A, St, Lazy;

  int rl(int p) {return p<<1;}
  int rr(int p) {return (p<<1)+1;}

  
  ll conquer(ll a, ll b) {
    return a+b;
  }

  void build(int i, int l, int r) {
    if(l == r) {
      St[i] = A[l];
    } else {
      int mid = (l+r)/2;
      build(rl(i), l, mid);
      build(rr(i), mid+1, r);
      St[i] = conquer(St[rl(i)], St[rr(i)]);
    }
  }

  void propagate(int i, int l, int r) {
    if (Lazy[i] != -1) {
      St[i] = Lazy[i] * (r - l + 1);
      if (l != r) { Lazy[rl(i)] = Lazy[rr(i)] = Lazy[i]; }
      else { A[l] = Lazy[i]; }
      Lazy[i] = -1;
    }
  }

  ll RSQ(int i, int l, int r, int tl, int tr) {
    propagate(i, tl, tr);
    if (l > tr || r < tl) return 0;
    if ((l <= tl) && (r >= tr)) return St[i];
    int mid = (tl+tr)/2;
    return conquer(RSQ(rl(i), l , r, tl, mid), RSQ(rr(i), l, r, min(tr,mid+1), tr));
  }

  void update(int i, int l, int r, int tl, int tr, int x) {
    propagate(i, tl, tr);
    if (l > tr || r < tl) return;
    if ((l <= tl) && (r >= tr)) {
      Lazy[i] = x;
      propagate(i, tl, tr);
    } else {
      int mid = (tl + tr) / 2;
      update(rl(i), l, r, tl, mid, x);
      update(rr(i), l, r, min(mid+1, tr), tr, x);
      St[i] = St[rl(i)] + St[rr(i)];
    }
  }

public:
  SegTree(int sz): n(sz), St(4*n), Lazy(4*n, -1), A(n) {}
  SegTree(const vector<ll> &initial):SegTree(initial.size()) {
    A = initial;
    build(1, 0, n-1);
  }

  void update(int i, int j, int val) { update(1,i,j, 0,n-1, val);}
  ll RSQ(int i, int j) { return RSQ(1, i,j,0,n-1);}
};


int main(){
	int n; cin>>n;
	vector<int> v(n);
	for(int &e: v) cin>>e;


	// inicialmente as posições estarão zeradas
	vector<ll> aux(n, 0LL);
	SegTree seg(aux);

	ordered_set added;

	ll sum = 0;

	// para um determinado v[i] só preciso saber de forma eficiente a soma de todos os elementos menores que ele que já apareceram no array
	for(int i = 0; i<n; i++){
		sum += seg.RSQ(v[i], n-1); 
		sum += v[i]*(added.size()-added.order_of_key(v[i]));

		added.insert(v[i]);
		seg.update(v[i]-1, v[i]-1, v[i]);
	}

	cout<<sum<<endl;
}