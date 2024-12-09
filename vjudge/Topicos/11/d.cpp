#include <bits/stdc++.h>
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

bool cmp(point &a, point &b){
    return a.id < b.id;
}

int orientation(point a, point b, point c) {
    int v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(point a, point b, point c, bool include_collinear) {
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

    sort(st.begin(), st.end(), cmp);
    a = st;
}

int main(){
    int n; cin>>n;
    vector<point> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i].x>>v[i].y;
        v[i].id = i+1;
    }
    convex_hull(v, true);
    bool first = true;

    for(auto &p : v){
        if(first){
            cout<<p.id;
            first = false; 
        } else cout<<" "<<p.id;
    } cout<<endl;
    
}