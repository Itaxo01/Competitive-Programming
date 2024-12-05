#include <bits/stdc++.h>
using namespace std;

struct Point {
    long double x, y;
    Point(long double x = 0, long double y = 0): x(x), y(y) {}
    int half(){
        return y < 0 || (y == 0 && x < 0);
    }
    bool operator != (Point a){
        return x != a.x || y != a.y;
    }
};

struct Vec {
    long double x, y;
    Vec(Point a, Point b): x(b.x - a.x), y(b.y - a.y) {}
};

long double cross(Vec a, Vec b){
    return a.x * b.y - a.y * b.x;
}

Point pivot = Point(0, 0);

int downmost(vector<Point> &p){
    int ans = 0;
    for(int i = 1; i<p.size(); i++){
        if(p[i].y < p[ans].y || (p[i].y == p[ans].y && p[i].x < p[ans].x))
            ans = i;
    }
    return ans;
}

bool cmp(Point a, Point b){
    if (a.half() != b.half())
        return a.half() < b.half();
    return cross(Vec(pivot, a), Vec(pivot, b)) > 0;
}

int ccw(Point a, Point b, Point c){
    return cross(Vec(a, b), Vec(a, c)) > 0;
}

vector<Point> ConvexHull(vector<Point> &p){
    if(p.size() <= 3){
        if(p.size() == 1) return p;
        if(p.size() == 2) {
            if(p[0] != p[1]) return p;
            return {p[0]};
        }
        if((p[0] != p[1]) && (p[0] != p[2]) && (p[1] != p[2])){
            if(ccw(p[0], p[1], p[2])) return p;
            return {p[0], p[2]};
        } else {
            if(p[0] != p[1]) return {p[0], p[1]};
            if(p[0] != p[2]) return {p[0], p[2]};
            if(p[1] != p[2]) return {p[1], p[2]};
            return {p[0]};
        }
    }

    vector<Point> s;
    s.push_back(p[0]); 
    s.push_back(p[1]);
    s.push_back(p[2]); 
    int i = 3;
    while(i < p.size()){
        int j = s.size() -1;
        if(ccw(s[j-1], s[j], p[i])) s.push_back(p[i++]);
        else s.pop_back();
    }
    return s;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(true){
        int n; cin>>n;
        if(!n) break;
        vector<Point> points(n);
        for(int i = 0; i<n; i++){
            int a, b; cin>>a>>b;
            points[i] = Point(a, b);
        }
        int p0 = downmost(points);
        swap(points[0], points[p0]);
        pivot = points[0];
        
        sort(++points.begin(), points.end(), cmp);
        vector<Point> hull = ConvexHull(points);
        cout<<hull.size()<<endl;
        for(auto x: hull)
            cout<<x.x<<" "<<x.y<<endl;
    }
}