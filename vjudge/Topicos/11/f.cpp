#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
    
    bool operator == (point const& t) const {
        return x == t.x && y == t.y;
    }
    bool operator < (point const& t) const {
        return x < t.x || (x == t.x && y < t.y);
    }
};

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

    a = st;
}

int dist(point &a, point &b){
    return (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y);
}

int maxDist(vector<point> &p){
    // Vai receber um vetor de pontos ordenados ccw por causa do convex hull (espero)
    int a = 0, b = 0;
    for(int i = 0; i<p.size(); i++){
        // Vai achar o ponto mais distante do ponto 0
        if(dist(p[a], p[i]) > dist(p[b], p[a])) b = i;
    }
    // A ideia é que o ponto mais distante de i+1 será ou b, b+1 ou b+2
    // Se for b mantém-se b, se for b+1, b = b+1, se for b+2, b = b+2
    int maior_dist = dist(p[0], p[b]);
    for(int i = 0; i<p.size(); i++){
        int b1 = dist(p[i], p[b]);
        int b2 = dist(p[i], p[(b+1+p.size() + p.size())%p.size()]);
        int b3 = dist(p[i], p[(b+2+p.size() + p.size())%p.size()]);
        if(b2 > b1){
            if(b3 > b2) b = (b+2)%p.size();
            else b = (b+1)%p.size();
        } else if(b3 > b1){
            b = (b+2)%p.size();
        }
        maior_dist = max(maior_dist, max(b1, max(b2, b3)));
    }
    return maior_dist;
}

int main(){
    int n; cin>>n;
    vector<point> p(n);
    for(int i = 0; i<n; i++){
        cin>>p[i].x>>p[i].y;
    }
    convex_hull(p);
    printf("%.9f\n", sqrt(maxDist(p)));
}