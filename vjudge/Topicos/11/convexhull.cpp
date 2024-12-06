#include <bits/stdc++.h>
#define ll long long
#define EPS 1e-9
using namespace std;

struct Point {
    ll x, y;
    Point(ll x = 0, ll y = 0): x(x), y(y) {}
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

ll cross(Point O, Point A, Point B){
    return (A.x - O.x)*(B.y - O.y) - (A.y - O.y)*(B.x - O.x);
}

ll dist(Point A, Point B){
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
        ll d1 = dist(aux[0], aux[1]);
        ll d2 = dist(aux[0], aux[2]);
        ll d3 = dist(aux[1], aux[2]);
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

    for (int i = 0; i < n; ++i){
        while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0)
            k--;
        H[k++] = P[i];
    }

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
    while(true){
        int n; cin >> n;
        if(!n) break;
        vector<Point> points(n);
        for(int i = 0; i < n; i++){
            ll a, b; cin >> a >> b;
            points[i] = Point(a, b);
        }

        vector<Point> hull = ConvexHull(points);
        cout<<hull.size()<<endl;
        // sort(hull.begin(), hull.end());
        for(auto e: hull){
            cout<<e.x<<" "<<e.y<<endl;
        }
    }
}