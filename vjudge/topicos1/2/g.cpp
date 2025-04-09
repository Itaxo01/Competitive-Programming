#include <bits/stdc++.h>
#define ld long double
using namespace std;

struct vec{
	ld x, y;
	vec(point a, point b){
		x = b.x-a.x; y = b.y-a.y;
	}
};

struct line{
	point a, b;
	line(point k1, point k2){
		if(k1.x < k2.x){
			a = k1, b = k2;
		} else if(k1.x == k2.x){
			if(k1.y < k2.y){
				a = k1, b = k2;
			} else a = k2, b = k1;
		} else a = k2, b = k1;
	}
	line(line l1, line l2){
		point low = (max(min(l1.a, l2.a), min(l1.b, l2.b)));
		point high = (min(max(l1.a, l2.a), max(l1.b, l2.b)));
		a = low, b = high;
	}
};

struct point{
	ld x, y;
	point(ld a = 0, ld b = 0){
		x = a; y = b;
	}
	bool operator<(point& a) {
		return (x < a.x) || (x == a.x && y < a.y);
	}
	bool operator<=(point& a){
		return (x == a.x && y == a.y) || 
				((x < a.x) || (x == a.x && y < a.y));
	}
};

bool collinear(point a, point b, point c){
	// a, b, c, mAB = mBC
	// (b.y-a.y)/(b.x-a.x) = (c.y-b.y)/(c.x-b.x)
	// (b.x-a.x)*(c.y-b.y) = (b.y-a.y)*(c.x-b.x)
	return (b.x-a.x)*(c.y-b.y) == (b.y-a.y)*(c.x-b.x);
}

bool point_in_line(point p, line l){
	if(!collinear(l.a, l.b, p)) return false;
	return (p.x>=min(l.a.x, l.b.x) && p.x <=max(l.a.x, l.b.x));
}

int cross(vec a, vec b){
	return a.x*b.y - a.y*b.x;
}

bool concurrent_lines(line l1, line l2){
	vec v1(l1.a, l1.b);
	vec v2(l2.a, l2.b);
	if(cross(v1, v2) != 0) return false;
	
}

bool are_points = false;
int main(){
	int a; cin>>a;
	vector<line> lines;
	vector<point> points;
	for(int i = 0; i<a; i++){
		int b, c, r; cin>>b>>c>>r;
		point k1(b-r, c), k2(b, c+r), k3(b+r, c), k4(b, c-r);
		line l1(k1, k2), l2(k2, k3), l3(k3, k4), l4(k4, k1);
		vector<line> lines_aux = {l1, l2, l3, l4};
		if(i == 0){
			lines = lines_aux;
		} else {
			if(are_points){
				vector<point> aux;
				for(auto e: points){
					for(auto l: lines_aux){
						if(point_in_line(e, l)) aux.push_back(e);
					}
				}
				points = aux;
			} else{
				vector<line> new_lines;
				for(auto l1: lines){
					for(auto l2: lines_aux){
						if(concurrent_lines(l1, l2)) {
							new_lines.push_back(line(l1, l2));
						} else if(intersept_lines(l1, l2)) {
							are_points = true;
							points.push_back(intersept(l1, l2));
						}
					}
				}
				lines = new_lines;
			}
		}
	}
}


void none(){
// The function for the manhattan distance will be similar to
// the circle one, except there will be no squared numbers.
// Instead, we will take the abs of them (It will form a diamond
// shaped square (losângulo)).
// |x-b| + |y-c| = r;
// There will be 4 vertices of a polygon, that means 4 line
// segments to consider. Those vertices are:
// (b-r, c) , (b, c+r), (b+r, c), (b, c-r);
// Or represented as vectors:
// ((b-r, c), (b, c+r)) , ((b, c+r), (b+r, c))
// ((b+r, c), (b, c-r)) , ((b, c-r), (b-r, c))
// When a new function is considered, there will be only two
// cases (Because it's garanteed that the functions will have a
// non-empty intersection):
// * The new function vectors is parallel to a previous vector
// 		in that case, we will forget the stored vectors and only
//		store the shortest of those two parallel vectors.
// * The new function crosses with the previous vectors in
// two points
//		in that case, we also forget the stored vectors and just
// 		work with the two points (could be a vector point 
//		pointing to itself) 
}