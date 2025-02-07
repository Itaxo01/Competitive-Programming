#include <bits/stdc++.h>
using namespace std;

struct point{
    double x, y;
    bool operator == (point const& t) const {
        return x == t.x && y == t.y;
    }
    bool operator < (point const& t) const {
        return x < t.x || (x == t.x && y < t.y);
    }

    point (double x = 0, double y = 0): x(x), y(y) {}
};

struct vec{
    double x, y;
    vec(double x, double y): x(x), y(y) {}
    vec(point a, point b){
        x = b.x - a.x;
        y = b.y - a.y;
    }
};

int orientation(point a, point b, point c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}


pair<bool, point> intercept(point &a, point &b, point &p, point &q){
	// check if coef a from ax+b of the line ab and pq are different
	// if the same check if b is also the same (in this problem that will be wrong but)
	double a1 = (a.y-b.y)/(a.x-b.x);
	double a2 = (p.y-q.y)/(p.x-q.x);
	if(a1 != a2){
		// Calculate where they met and if that point is in the range
		// a1x - a2x = p.y - a.y - > x = (p.y - a.y)/(a1 - a2), y = a1x+a.y
		double x = (p.y - a.y)/(a1 - a2);
		double y = a1*x + a.y;
		cout<<x<<" "<<y<<endl;
		if(x >= a.x && x >= p.x && x <= b.x && x <= q.x)
			if(y >= a.y && y >= p.y && y <= b.y && y <= q.y)
				return {true, {x, y}};
		return {false, {x, y}};
	}
	return {false, {-1, -1}};
}

void cutPolygon(vector<point> &v, point &p1, point &p2, point &f){
	int n = v.size();
	vector<point> new_v; // new polygon
	for(int i = 1; i<n; i++){
		pair<bool, point> interception = intercept(v[i], v[i-1], p1, p2);
		if(interception.first){
			new_v.push_back(interception.second);
		}
	}
	if(new_v.empty()) return;
	// for(int i = 0; i<n; i++){
	// 	// it's certain that if the new_v isn't empty, it has two points
	// 	// will check for every point of the polygon if it's on the same side as
	// 	// the fountain or no (with a cross product between the fountain
	// 	// , a interception point and the point in question)
	// 	if(orientation(new_v[0], v[i], f) > 0) new_v.push_back(v[i]);
	// }
	// v = new_v;
}

double area(vector<point> &p){
    double sum = 0;
    for(int i = 0; i<p.size(); i++){
        sum += p[i].x*p[(i+1)%p.size()].y - p[i].y*p[(i+1)%p.size()].x;
    }
    return sum/2;
}

int main(){
	double a, b, c, d, e;
    int count = 1;
    while(cin>>a>>b>>c>>d>>e){
        vector<point> v; // Poligono inicial

        v.push_back({0, 0});
        v.push_back({b, 0});
        v.push_back({b, c});
        v.push_back({0, c});
        v.push_back({0, 0});
        point p = {d, e}; 
        for(int i = 0 ; i < (int)a; i++){
            point p1, p2; cin>>p1.x>>p1.y>>p2.x>>p2.y;
				cutPolygon(v, p1, p2, p);
        }
        printf("Case #%d: %.3f\n", count++, area(v));
    }
}