#include <bits/stdc++.h>
#define ld long double
#define hp halfplane
using namespace std;
const ld eps = 1e-9, inf = 1e9;

struct point{
	ld x, y;
	point(ld x = 0, ld y = 0): x(x), y(y){};
	friend point operator + (const point& p, const point& q) {
        return point(p.x + q.x, p.y + q.y); 
    }
    friend point operator - (const point& p, const point& q) { 
        return point(p.x - q.x, p.y - q.y); 
    }
    friend point operator * (const point& p, const ld& k) { 
        return point(p.x * k, p.y * k); 
    }
    friend ld dot(const point& p, const point& q) {
        return p.x * q.x + p.y * q.y;
    }
    friend ld cross(const point& p, const point& q) { 	
        return p.x * q.y - p.y * q.x; 
    }
	friend ld dist(const point&p, const point& q) {
		return pow(p.x-q.x, 2)+pow(p.y-q.y, 2);
	}
	bool operator < (const point&p) const{
		return x<p.x || (x == p.x && y<p.y);
	}
};

struct halfplane{
	point p, pq;
	ld angle;
	halfplane(){}
	halfplane(point a, point b): p(a), pq(b-a){
		angle = atan2l(pq.y, pq.x);
	}
	bool out(const point& r){
		return cross(pq, r - p) < -eps;
	}
	bool operator < (const halfplane &e) const{
		return angle < e.angle;
	}
	friend point intersection(const halfplane& s, const halfplane & t){
		ld alpha = cross((t.p - s.p), t.pq)/cross(s.pq, t.pq);
		return s.p + (s.pq * alpha);
	}
};

vector<point> hp_intersect(vector<hp> &h){
	point box[4] = {
		point(inf, inf),
		point(-inf, inf),
		point(-inf, -inf),
		point(inf, -inf)
	};
	for(int i = 0; i<4; i++){
		hp aux(box[i], box[(i+1)%4]);
		h.push_back(aux);
	}
	sort(h.begin(), h.end());
	deque<hp> dq;
	int len = 0;
	for(int i = 0; i < h.size(); i++){
		while(len > 1 && h[i].out(intersection(dq[len-1], dq[len-2]))){
			dq.pop_back(); 
			--len;
		}
		while(len > 1 && h[i].out(intersection(dq[0], dq[1]))){
			dq.pop_front();
			--len;
		}
		if(len > 0 && fabsl(cross(h[i].pq, dq[len-1].pq)) < eps){
			if(dot(h[i].pq, dq[len-1].pq) < 0.0) 
				return vector<point>();
			if (h[i].out(dq[len-1].p)) {
				dq.pop_back();
				--len;
			}
			else continue;
		}

		dq.push_back(h[i]);
		++len;
	}
	while (len > 2 && dq[0].out(intersection(dq[len-1], dq[len-2]))) {
        dq.pop_back();
        --len;
    }
    while (len > 2 && dq[len-1].out(intersection(dq[0], dq[1]))) {
        dq.pop_front();
        --len;
    }
    if (len < 3) return vector<point>();

    vector<point> ret(len);
    for(int i = 0; i+1 < len; i++) {
        ret[i] = intersection(dq[i], dq[i+1]);
    }
    ret.back() = intersection(dq[len-1], dq[0]);
    return ret;
}

point origin(0, 0);
bool check(vector<point> &p, ld d){
	for(auto e: p){
		if(dist(e, origin) > d*d) return false;
	} return true;
}

int main(){
	int n; ld d; cin>>n>>d;
	vector<hp> v(n);
	for(int i = 0; i<n; i++){
		int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
		point p1(x1, y1), p2(x2, y2);
		if(cross(p2-p1, origin-p1) > 0)
			v[i] = hp(p1, p2);
		else 
			v[i] = hp(p2, p1);
	}
	int l = 0, r = n;
	while(l<r){
		int m = (l+r)/2;
		vector<hp> aux(v.begin(), v.begin() + m);
		vector<point> p = hp_intersect(aux);
		if(check(p, d)){
			r = m;
		} else l = m+1;
	}
	int m = (l+r)/2;
	vector<hp> aux(v.begin(), v.begin() + m);
	vector<point> p = hp_intersect(aux);
	if(check(p, d)) cout<<m<<endl;
	else cout<<"*\n";
}