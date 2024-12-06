#include <bits/stdc++.h>
#define ld long double
#define EPS 1e-9
using namespace std;

struct Point {
    ld x, y;
    Point(ld x = 0, ld y = 0): x(x), y(y) {}
    bool operator < (const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
    bool operator == (const Point& p) const {
        return x == p.x && y == p.y;
    }
    bool operator != (const Point& p) const {
        return x != p.x || y != p.y;
    }
};

ld cross(Point O, Point A, Point B){
    return (A.x - O.x)*(B.y - O.y) - (A.y - O.y)*(B.x - O.x);
}

ld dist(Point A, Point B){
    return pow(B.x-A.x, 2) + pow(B.y - A.y, 2);
}

vector<Point> chullmenorigual3(vector<Point> &P){
    int n = P.size();
    if (n <= 1) return P;
    if (n == 2) {
        if(P[0] == P[1]) return {P[0]};
        return P;
    }
    vector<Point> aux; aux.push_back(P[0]);
    if(P[1] != P[0]) aux.push_back(P[1]);
    if(P[2] != P[0] && P[2] != P[1]) aux.push_back(P[2]);
    if(aux.size() == 3){
        if(cross(aux[0], aux[1], aux[2]) != 0) return aux;
        ld d1 = dist(aux[0], aux[1]);
        ld d2 = dist(aux[0], aux[2]);
        ld d3 = dist(aux[1], aux[2]);
        if(d1 >= d2 && d2 >= d3) return {aux[0], aux[1]};
        if(d2 >= d3) return {aux[0], aux[1]};
        return {aux[1], aux[2]};            
    }
    return aux;
}

vector<Point> ConvexHull(vector<Point> &P){
    int n = P.size(), k = 0;
    if(n <= 3) return chullmenorigual3(P);
    sort(P.begin(), P.end());
    vector<Point> H(2*n);

    // Build lower hull
    for (int i = 0; i < n; ++i){
        while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0)
            k--;
        H[k++] = P[i];
    }

    // Build upper hull
    for (int i = n-2, t = k+1; i >= 0; --i){
        while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0)
            k--;
        H[k++] = P[i];
    }

    H.resize(k-1);
    return H;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<Point> points(n);
    for(int i = 0; i < n; i++){
        ld a, b; cin >> a >> b;
        points[i] = Point(a, b);
    }

    vector<Point> hull = ConvexHull(points);
    ld maior_dist = -1;
    Point pi, pj;
    int s = hull.size();
    for(int i = 0; i<s; i++){
        for (int j = 0; j<s; j++){
            Point center = {(hull[i].x+hull[j].x)/2.0, (hull[i].y+hull[j].y)/2.0};
            cout<<center.x<<" "<<center.y<<endl;
            ld d = dist(hull[i], hull[j]);
            if(d > maior_dist){
                maior_dist = d;
                pi = hull[i]; pj = hull[j];
            }
        }
    }
    Point center = {(pi.x+pj.x)/2.0, (pi.y+pj.y)/2.0};
    ld raio = sqrt(dist(center, pi));
    ld circ = 3.14*4*2*raio;
    printf("%.2Lf %.2Lf %.2Lf %.2Lf\n", center.x, center.y, raio, circ);
}