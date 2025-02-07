#include <bits/stdc++.h>
#define ld long double
using namespace std;

struct point{
	public:
		ld x, y;
		point(ld a = 0, ld b = 0){
			x = a;
			y = b;
		}
		bool operator < (const point& a) const{
			return x < a.x || (x == a.x && y < a.y);
		}
};

int quad(point a) {
	if(a.x >= 0) {
		if(a.y >= 0) return 1;
		return 4;
	}
	if(a.y >= 0) return 2;
	return 3;
}

point axis = {0, 0};

bool cmp(point a, point b){
	int q1 = quad(a), q2 = quad(b);
	if(q1 != q2) return q1 < q2;
	int cross = a.x*b.y - b.x*a.y;
	return cross > 0;
}

ld mag(point a){
	return sqrt(a.x*a.x + a.y*a.y);
}

ld angle(point a, point b){
	ld dot = a.x*b.x + a.y*b.y;
	ld m = mag(a) * mag(b);
	return acos(dot/m);
}

signed main(){
	int n; cin>>n;
	vector<point> v(n);
	map<point, int> mp;
	for(int i = 0; i<n; i++){
		ld a, b; cin>>a>>b;
		v[i] = {a, b};
		mp[v[i]] = mp.size();
	}
	sort(v.begin(), v.end(), cmp);

	ld menor = angle(v[n-1], v[0]);
	if(isnan(menor)) menor = 4;
	vector<int> menores = {mp[v[n-1]], mp[v[0]]};
	for(int i = 0; i<n-1; i++){
		ld ang = angle(v[i], v[i+1]);
		if(ang < menor){
			menor = ang;
			menores[0] = mp[v[i]]; menores[1] = mp[v[i+1]];
		}
	}

	cout<<menores[0]+1<<" "<<menores[1]+1<<endl;
}