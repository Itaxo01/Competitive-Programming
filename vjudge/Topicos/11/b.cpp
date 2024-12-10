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
    if(a.size() <= 2) return;
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

int norm_sq(point &a){
    return a.x*a.x+a.y*a.y;
}

int dot(point &ab, point &cb){
    return (ab.x*cb.x + ab.y*cb.y);
}

double angle(point &a, point &b, point &c){
    point ab = {b.x - a.x, b.y - a.y};
    point cb = {b.x - c.x, b.y - c.y};

    double dt = dot(ab, cb);

    double abSqr = norm_sq(ab);
    double cbSqr = norm_sq(cb);

    double cosSqr = dt*dt / abSqr / cbSqr;
    return acos(dot(ba, bc)/sqrt(norm_sq(ba)*norm_sq(bc)));
}

bool insidePolygon(point pt, vector<point> &p) {
    int n = p.size();
    if(n <= 2) return false;
    bool on_polygon = false;
    
    for (int i = 0; i < n-1; i++){
        if(collinear(p[i], pt, p[i+1])){
            if(pt.x == p[i].x && pt.x == p[i+1].x){
                if((pt.y <= p[i].y && pt.y >= p[i+1].y) ||
                    (pt.y <= p[i+1].y && pt.y >= p[i].y)){
                        return true;
                    }
            } else {
                if((pt.x <= p[i].x && pt.x >= p[i+1].x) ||
                    (pt.x <= p[i+1].x && pt.x >= p[i].x)){
                        return true;
                    }
            }
        }
    }
    
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
        if(count>1) cout<<endl;
        vector<point> cops;
        vector<point> robbers;
        vector<point> citizens;

        for(int i = 0; i<a; i++){
            point p; cin>>p.x>>p.y;
            cops.push_back(p);
        }
        convex_hull(cops, true);

        for(int i = 0; i<b; i++){
            point p; cin>>p.x>>p.y;
            robbers.push_back(p);
        }
        convex_hull(robbers, true);        

        for(int i = 0; i<c; i++){
            point p; cin>>p.x>>p.y;
            citizens.push_back(p);
        }
        printf("Data set %d:\n", count++);
        
        cout<<insidePolygon(citizens[0], cops)<<endl;

        // for(auto &p:citizens){
        //     printf("     Citizen at (%d, %d) is ", p.x, p.y);
        //     if(insidePolygon(p, cops) == 1) cout<<"safe.\n";
        //     else if(insidePolygon(p, robbers) == 1) cout<<"robbed.\n";
        //     else cout<<"neither.\n";
        // }
    }
    
}