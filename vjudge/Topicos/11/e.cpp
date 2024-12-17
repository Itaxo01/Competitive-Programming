#include <bits/stdc++.h>
#define EPS 1e-9
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

point lineIntersectSeg(point p, point q, point A, point B) {
    double a = B.y-A.y, b = A.x-B.x, c = B.x*A.y- A.x*B.y;
    double u = fabs(a*p.x + b*p.y + c);
    double v = fabs(a*q.x + b*q.y + c);
    return point((p.x*v + q.x*u) / (u+v), (p.y*v + q.y*u) / (u+v));
}

int orientation(point a, point b, point c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

double cross(vec a, vec b){
    return a.x*b.y - a.y*b.x;
}


void cutPolygon(vector<point> &v, point a, point b) {
    vector<point> p;
    for (int i = 0; i < (int)v.size(); ++i) {
        double l1 = orientation(a, b, v[i]), l2 = 0;
        if (i != (int)v.size()-1) l2 = orientation(a, b, v[i+1]);
        if (l1 >-EPS) p.push_back(v[i]);
        if (l1*l2 <-EPS)
            p.push_back(lineIntersectSeg(v[i], v[i+1], a, b));
    }
    if (!p.empty() && !(p.back() == p.front()))
        p.push_back(p.front());
    v = p;
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
            if(orientation(p1, p2, p) > 0){
                cutPolygon(v, p1, p2);
            } else {
                cutPolygon(v, p2, p1);
            }
        }
        printf("Case #%d: %.3f\n", count++, area(v));
    }
}