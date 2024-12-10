#include <bits/stdc++.h>
#define ll long long
#define pii array<int,2>
#define nx(i) (i+1)%n
#define pv(i) (i-1+n)%n
using namespace std;

struct point {
    int x, y;
    
    bool operator == (point const& t) const {
        return x == t.x && y == t.y;
    }
    bool operator < (point const& t) const {
        return x < t.x || (x == t.x && y < t.y);
    }

	 point operator+(const point &p) {
        return {x + p.x, y + p.y};
    }

    point operator-(const point &p) {
        return {x - p.x, y - p.y};
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

double dist(point &a, point &b){
	 return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int cross(point p1, point p2) {
    return p1.x * p2.y - p1.y * p2.x;
}

double maior_dist(vector<point> &p){
    int n = p.size();
    if(n < 2) return 0;
    else if(n == 2) return dist(p[0], p[1]);
    else{
        int i = n-1, j = 0, k = 1;
        double res = 0;
        while(abs(cross(p[j]-p[i], p[k+1]-p[i]) >
                  abs(cross(p[j]-p[i], p[k]-p[i])))){
            k++;
        }
        i = 0, j = k;
        while(i <= k && j < n){
            res = max(dist(p[i], p[j]), res);
            while(j<n-1 && abs(cross(p[i+1]-p[i], p[j+1]-p[i]) >
                      abs(cross(p[i+1]-p[i], p[j]-p[i])))){
                j++;
                res = max(dist(p[i], p[j]), res);
            }
            i++;
        }
        return res;
    }
}

int main(){
    int n; cin>>n;
    vector<point> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i].x>>v[i].y;
    }
    convex_hull(v, true);

	//  long long maior_dist = 0;
	//  for(int i = 0; i<v.size(); i++){
	// 	for(int j = 0; j<v.size(); j++){
	// 		if (i == j) continue;
	// 		maior_dist = max(maior_dist, dist(v[i], v[j]));
	// 	}
	//  }
	//  printf("%.8lf\n", sqrt(maior_dist));


	double res = maior_dist(v);

	printf("%.8lf\n", sqrt(res));
	 return 0;
}