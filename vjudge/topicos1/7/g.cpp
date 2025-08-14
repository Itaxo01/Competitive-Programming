#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Range{
	ll a, b, h; // começa em a, termina em b, altura h
	Range(ll a, ll b, ll c): a(a), b(b), h(c) {};
	bool operator < (const Range &r) const{
		return b < r.a;
	}
	bool cmp (ll k) const{
		return a < k;
	}
};

void try_merge(set<Range> &ranges, set<Range>::iterator r2){
	if(r2 != ranges.begin()){
		auto r1 = prev(r2);
		if(r1->h == r2->h){
			Range r4(r1->a, r2->b, r2->h);
			ranges.erase(r1);
			ranges.erase(r2);
			auto [a, b] = ranges.insert(r4);
			if(b) r2 = a;
		}
	} 
	if(r2 != ranges.end()){
		auto r3 = next(r2);
		if(r2->h == r3->h){
			Range r4(r2->a, r3->b, r2->h);
			ranges.erase(r2);
			ranges.erase(r3);
			ranges.insert(r4);
		}
	}
}

signed main(){
	set<Range> ranges;
	ranges.insert({0, (ll)(1000000000000000002), 0});
	ll n; cin>>n;	
	for(int i = 0; i<n; i++){
		char c; ll l, p; cin>>c>>l>>p;
		if(c == '|') {
			// peça horizontal, divido o segmento em 1, 2 ou 3 partes
			// uma para a que ficar com a peça, e as (possivelmente) duas do lado
			Range r2(p, p, l);
			auto it = ranges.lower_bound(r2);
			ll s1 = it->a, e1 = r2.a-1;
			ll s2 = r2.a, e2 = r2.b; // s2 == r2 - it->altura
			ll s3 = r2.b+1, e3 = it->b;
			Range r1(s1, e1, it->h);
			Range r3(s3, e3, it->h);
			r2.h += it->h;
			ranges.erase(it);
			if(s1 <= e1) ranges.insert(r1);//, cout<<r1.a<<" "<<r1.b<<" "<<r1.h<<endl;
			if(s3 <= e3) ranges.insert(r3);//, cout<<r3.a<<" "<<r3.b<<" "<<r3.h<<endl;
			ranges.insert(r2);//, cout<<r2.a<<" "<<r2.b<<" "<<r2.h<<endl;
			try_merge(ranges, ranges.find(r2));
			cout<<'S';
		} else {
			Range r2(p, p+l-1, 1);
			auto it = ranges.lower_bound(r2);
			if(r2.b > it->b) cout<<'U'; // UNSAFE
			else { // vou mesclar parcial ou totalmente a linha com o bloco abaixo
				ll s1 = it->a, e1 = r2.a-1;
				ll s2 = r2.a, e2 = r2.b;
				ll s3 = r2.b+1, e3 = it->b;
				Range r1(s1, e1, it->h);
				Range r3(s3, e3, it->h);
				r2.h += it->h;
				ranges.erase(it);
				if(s1 <= e1) ranges.insert(r1);
				if(s3 <= e3) ranges.insert(r3);
				ranges.insert(r2);
				try_merge(ranges, ranges.find(r2));
				cout<<'S';
			}
		}
	}
	cout<<endl;
}