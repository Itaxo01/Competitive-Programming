#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

struct point {
    int x, y, id;

    bool operator == (point const& t) const {
        return x == t.x && y == t.y;
    }
    bool operator < (point const& t) const {
        return x < t.x || (x == t.x && y < t.y);
    }
};

struct vec {
    point a, b;
    vec(point a, point b): a(a), b(b) {}
};

bool cmp(point &a, point &b){
    return a.id < b.id;
}

int orientation(point a, point b, point c) {
    int v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(point a, point b, point c, bool include_collinear = false) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool collinear(point a, point b, point c) { return orientation(a, b, c) == 0; }

void convex_hull(vector<point>& a, bool include_collinear = false) {
    point p0 = *min_element(a.begin(), a.end(), [](point a, point b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(), [&p0](const point& a, const point& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    });
    if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<point> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    if (include_collinear == false && st.size() == 2 && st[0] == st[1])
        st.pop_back();

    a = st;
}

int dist(point &a, point &b){
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int norm_sq(vec &v){
    return dist(v.a, v.b);
}

int dot(vec &a, vec &b){
    return (a.a.x - a.b.x)*(b.a.x - b.b.x) + (a.a.y - a.b.y)*(b.a.y - b.b.y);
}

double angle(point &a, point &b, point &c){
    vec ba = vec(b, a), bc = vec(b, c);
    return acos(dot(ba, bc)/sqrt(norm_sq(ba)*norm_sq(bc)));
}

bool insidePolygon(point pt, vector<point> &p) {
    int n = p.size();
    if (n <= 2) return false;
    bool on_polygon = false;
    
    for (int i = 0; i < n-1; i++){
        int d1, d2, d3;
        d1 = (dist(p[i], pt) + dist(pt, p[i+1]) - dist(p[i], p[i+1])); 
        if (d1 == 0){
            on_polygon = true;
            break;
        }
        d2 = (dist(p[i], p[i+1]) + dist(pt, p[i+1]) - dist(p[i], pt));
        if (d2 == 0){
            on_polygon = true;
            break;
        }
        d3 = 
        if (d3 == 0){
            on_polygon = true;
            break;
        }
    }
        
    
    if (on_polygon) return true;

    double sum = 0.0;
    for (int i = 0; i < n-1; ++i) {
        if (orientation(pt, p[i], p[i+1]) == 1)
            sum += angle(p[i], pt, p[i+1]);
        else
            sum-= angle(p[i], pt, p[i+1]);
    }
    return fabs(sum) > M_PI ? true : false;
}

namespace std {
    template <>
    struct hash<point> {
        std::size_t operator()(const point& p) const noexcept {
            std::size_t hx = std::hash<double>{}(p.x);
            std::size_t hy = std::hash<double>{}(p.y);
            return hx ^ (hy << 1); // Combine the hashes
        }
    };
}

int main(){
    int count = 1;
    while(true){
        int a, b, c; cin>>a>>b>>c;
        if(!a && !b && !c) break;
        vector<point> cops;
        vector<point> robbers;
        vector<point> citizens;

        unordered_set<point> cops_s;
        unordered_set<point> robbers_s;
        unordered_set<point> citizens_s;


        for(int i = 0; i<a; i++){
            point p; cin>>p.x>>p.y;
            if(cops_s.find(p) != cops_s.end()) continue;
            cops.push_back(p);
            cops_s.insert(p);
        }
        convex_hull(cops, true);

        for(int i = 0; i<b; i++){
            point p; cin>>p.x>>p.y;
            if(robbers_s.find(p) != robbers_s.end()) continue;
            robbers.push_back(p);
            robbers_s.insert(p);
        }
        convex_hull(robbers, true);

        for(int i = 0; i<c; i++){
            point p; cin>>p.x>>p.y;
            if(citizens_s.find(p) != citizens_s.end()) continue;
            citizens.push_back(p);
            citizens_s.insert(p);
        }
        printf("Data set %d:\n", count++);
        
        for(auto &p:citizens){
            printf("     Citizen at (%d, %d) is ", p.x, p.y);
            if(insidePolygon(p, cops) == 1) cout<<"safe.\n";
            else if(insidePolygon(p, robbers) == 1) cout<<"robbed.\n";
            else cout<<"neither.\n";
        }
    }
    
}