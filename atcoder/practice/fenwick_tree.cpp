#include <bits/stdc++.h>
#define ll long long
using namespace std;



struct Fenwick_tree{
	vector<ll> tree;
	int maxi;
	Fenwick_tree(vector<ll> &v){
		maxi = v.size();
		tree.assign(maxi+1, 0);
		for(int i = 1; i<=maxi; i++){
			update(i, v[i-1]);
		}
	}

	void update(int i, ll x){
		while(i <= maxi){
			tree[i] += x;
			i += (i & -i);
		}
	}
	ll read(int i){
		ll s = 0;
		while(i > 0){
			s += tree[i];
			i -= (i & -i);
		}
		return s;
	}

	ll read(int i, int j){
		if(j < i) swap(i, j);
		return read(j) - read(i);
	}
};

int main(){
	int n, q; cin>>n>>q;
	vector<ll> v(n);
	for(ll &e: v) cin>>e;
	Fenwick_tree f(v);

	for(int i = 0; i<q; i++){
		int a, b, c; cin>>a>>b>>c;
		if(a){
			cout<<f.read(b, c)<<endl;
		} else {
			f.update(b+1, c);
		}
	}

}