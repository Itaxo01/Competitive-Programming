#include <bits/stdc++.h>
using namespace std;

struct point {
    double x, y;
    
    bool operator == (point const& t) const {
        return x == t.x && y == t.y;
    }
    bool operator < (point const& t) const {
        return x < t.x || (x == t.x && y < t.y);
    }
};

int orientation(point a, point b, point c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y); // cross product between two vectors in R2, can be extracted from the matrix
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

void radial_sort(vector<point>& a, bool include_collinear = false) {
    point p0 = *min_element(a.begin(), a.end(), [](point a, point b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x); // search the entire vector for the lowest (y, x) point
    });
    
    sort(a.begin(), a.end(), [&p0](const point& a, const point& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    });
}

int main(){
    
}
