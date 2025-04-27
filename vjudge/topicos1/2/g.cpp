#include <bits/stdc++.h>
#define ld long double
#define EPS 1e-9
using namespace std;

struct point{
	ld x, y;
	point(ld a = 0, ld b = 0){
		x = a, y = b;
	}

	bool operator<(const point &p) const{
		return x < p.x || (x == p.x && y < p.y);
	}
};


struct line{
	ld a, b;
	ld min_x, max_x;
	ld min_y, max_y;
	line(point p1, point p2){
		min_x = min(p1.x, p2.x);
		max_x = max(p1.x, p2.x);
		if(min_x != max_x){
			a = (p1.y-p2.y)/(p1.x-p2.x);
			b = p1.y-a*p1.x;
		} else{
			a = 1;
			b = p1.y-p1.x;
		}

		min_y = min_x*a + b;
		max_y = max_x*a + b;
	}
	line(line l1, line l2){
		a = l1.a; b = l1.b;
		min_x = max(l1.min_x, l2.min_x);
		max_x = min(l1.max_x, l2.max_x);
		min_y = min_x*a + b;
		max_y = max_x*a + b;
	}
	line(line l1, line l2, bool concurrent){
		a = l1.a; b = l1.b;
		int x = (l2.b-l1.b)/(l1.a-l2.a);
		min_x = x;
		max_x = x;

		min_y = min_x*a + b;
		max_y = max_x*a + b;
	}

	bool operator<(const line& l) const{
		return a < l.a || 
			(a == l.a && b < l.b || 
			(a == l.a && b == l.b && min_x < l.min_x ||
			(a == l.a && b == l.b && min_x == l.min_x && max_x < l.max_x ||
			(a == l.a && b == l.b && min_x == l.min_x && max_x == l.max_x && min_y < l.min_y ||
			(a == l.a && b == l.b && min_x == l.min_x && max_x == l.max_x && min_y == l.min_y && max_y < l.max_y)))));
	}
};

bool collinear(line l1, line l2){
	if(l1.a == l2.a && l1.b == l2.b){
		int min_x = max(l1.min_x, l2.min_x);
		int max_x = min(l1.max_x, l2.max_x);
		return min_x <= max_x;
	} return false;
}

bool concurrent(line l1, line l2){
	if(l1.a != l2.a){
		int x = (l2.b-l1.b)/(l1.a-l2.a);
		if(x >= l1.min_x && x <= l1.max_x && x >= l2.min_x && x <= l2.max_x){
			return true;
		}
	}
	return false;
}
bool is_integer(ld x){
	return (x - x/1)<EPS;
}

int main(){
	int a; cin>>a;
	int b, c, r; cin>>b>>c>>r;
	point k1(b-r, c), k2(b, c+r), k3(b+r, c), k4(b, c-r);
	line l1(k1, k2), l2(k2, k3), l3(k3, k4), l4(k4, k1);
	
	set<line> linhas = {l1, l2, l3, l4};
	for(int i = 1; i<a; i++){
		cin>>b>>c>>r;
		point k1(b-r, c), k2(b, c+r), k3(b+r, c), k4(b, c-r);
		line l1(k1, k2), l2(k2, k3), l3(k3, k4), l4(k4, k1);
		set<line> linhas_aux = {l1, l2, l3, l4};

		set<line> new_lines;
		for(auto l1: linhas){
			// cout<<"l1: "<<l1.a<<" "<<l1.b<<" ("<<l1.min_x<<","<<l1.max_x<<")\n";
			for(auto l2:linhas_aux){
				if(collinear(l1, l2)){
					line l3(l1, l2);
					// cout<<"Collinear\n";
					// cout<<l2.a<<" "<<l2.b<<" ("<<l2.min_x<<","<<l2.max_x<<")\n";
					// cout<<l3.a<<" "<<l3.b<<" ("<<l3.min_x<<","<<l3.max_x<<")\n";
					new_lines.insert(l3);
				}
				else if(concurrent(l1, l2)){
					line l3(l1, l2, true);
					// cout<<"Concurrent\n";
					// cout<<l2.a<<" "<<l2.b<<" ("<<l2.min_x<<","<<l2.max_x<<")\n";
					// cout<<l3.a<<" "<<l3.b<<" ("<<l3.min_x<<","<<l3.max_x<<")\n";
					new_lines.insert(l3);
				}
			}
		}
		linhas = new_lines;
		// for(auto l:linhas){
		// 	cout<<l.a<<" "<<l.b<<" ("<<l.min_x<<","<<l.max_x<<")\n";
		// }
		cout<<endl;
	}
	set<point> pontos;
	for(auto l:linhas){
		for(int x = l.min_x; x<=l.max_x; x++){
			ld y = x*l.a+l.b;
			if(is_integer(y)) pontos.insert(point(x, y));
		}
	}
	for(auto e: pontos){
		cout<<e.x<<" "<<e.y<<endl;
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