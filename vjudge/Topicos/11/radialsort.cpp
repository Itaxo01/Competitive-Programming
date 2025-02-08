// This is just the Codeforces edu 1 c that I did
#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
    point(int a = 0, int b = 0){
		x = a, y = b;
	 }
    bool operator == (point const& t) const {
        return x == t.x && y == t.y;
    }
    bool operator < (point const& t) const {
        return x < t.x || (x == t.x && y < t.y);
    }
};

int q(point a){
	if(a.y >= 0 and a.x > 0) return 0;
	if(a.y > 0 and a.x <= 0) return 1;
	if(a.y <= 0 and a.x < 0) return 2;
	return 3;
}

int orientation(point a, point b, point c) {
    int v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y); // cross product between two vectors in R2, can be extracted from the matrix
                                                          // i j k determinant, where k is 1. The two vectors are (c, a) and (c, b),
                                                          // c acts as the origin. 
    if (v < 0) return -1; // going from (c, a) to (c, b), if the cross product is negative there is a right curve, so (c, b) is
                          // clockwise based on (c, a)
    if (v > 0) return +1; // same thing but left curve, so (c, b) is counter-clockwise based on (c, a)
    return 0; // otherwise they are collinear
}

bool cw(point a, point b, point c, bool include_collinear) {
    int o = orientation(a, b, c); // we can sort clockwise (cw) or counter-clockwise(ccw), the only thing that changes is the next line
    return o < 0 || (include_collinear && o == 0); // works as a comparation function, returns true if vector (c, a) is less than (c, b),
                                                  // wich means true if (c, a) takes a right turn to get to (c, b). Include collinear is trivial
}
bool collinear(point a, point b, point c) { return orientation(a, b, c) == 0; }

void radial_sort(vector<point>& a) {
	 // for the convex hull, p0 is the lowest (y, x) point
	 // here it is the origin.
    point p0 = (0, 0);
    
    sort(a.begin(), a.end(), [&p0](const point& a, const point& b) {
        int qa = q(a), qb = q(b);
		  if(qa != qb) return qa < qb;
		
		  int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o > 0; 
    });
}

long double angle(const point& a, const point& b) {
    // Convert to long double for precision
    long double dot = (long double)a.x * b.x + (long double)a.y * b.y;
    long double cross = (long double)a.x * b.y - (long double)a.y * b.x;
    // atan2 returns the signed angle in radians; use fabs if smallest unsigned angle is desired
    return atan2(fabs(cross), dot);
}

int main(){
	int n; cin>>n;
	vector<point> p(n);
	map<point, int> m;
	for(int i = 0; i < n; i++){
		point a; cin>>a.x>>a.y;
		m[a] = m.size();
		p[i] = a;
	}
	// cout<<"Before sort:\n";
	// for(int i = 0; i<n; i++){
	// 	printf("%d, %d %d\n", p[i].x, p[i].y, m[p[i]]);
	// }
	// cout<<"\n";
	

	radial_sort(p);
	// cout<<"After sort:\n";
	// for(int i = 0; i<n; i++){
	// 	printf("%d, %d\n", p[i].x, p[i].y);
	// }
	// cout<<"\n";
	long double min_angle = angle(p[n-1], p[0]);
	point min_a = p[0], min_b = p[n-1];
	for(int i = 0; i<n-1; i++){
		long double c = angle(p[i], p[i+1]); // biggest the cosine is, smallest the angle, since it just increases from pi to 0.
		
		if(c < min_angle) {
			min_angle = c;
			min_a = p[i];
			min_b = p[i+1];
		}
	}
	cout<<m[min_a]+1<<" "<<m[min_b]+1<<endl;
}
