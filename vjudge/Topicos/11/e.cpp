#include <bits/stdc++.h>
using namespace std;

struct point{
    int x, y;
    bool operator == (point const& t) const {
        return x == t.x && y == t.y;
    }
    bool operator < (point const& t) const {
        return x < t.x || (x == t.x && y < t.y);
    }
};

struct line{
    point a, b;
};

int main(){
    int a, b, c, d, e;
    vector<point> v(4);
    v.push_back({0, 0});
    v.push_back({0, b});
    v.push_back({a, b});
    v.push_back({a, 0});
    for(int i = 0 ; i < a; i++){
        int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
    }
}