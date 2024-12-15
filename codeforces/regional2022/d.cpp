#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

struct vec;

struct point{
	double x, y;
	point(double a = 0.0, double b = 0.0): x(a), y(b) {}
	bool operator == (point &p) {
		return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
	}
	bool operator != (point &p) {
		return !(*this == p);
	}
	point operator - (point &p) {
		return {x-p.x, y-p.y};
	}
	point operator + (point &p) {
		return {x+p.x, y+p.y};
	}
	void operator *= (int k) {
		x *= k; y*= k;
	}
};


int quadrante(point p, point middle){
	if(p.x > middle.x){
		if(p.y > middle.y) return 0;
		return 3;
	} 
	if(p.y > middle.y) return 1;
	return 2;
}

void solve(int n, point p){
	point atual = p;
	point middle = {pow(2, n-1), pow(2, n-1)};
	vector<point> atr = {{pow(2, n), pow(2, n)}, {0.0, pow(2, n)},
								 {0.0, 0.0}, {pow(2, n), 0.0}};
	int count = 0;
	while(atual != middle){
		count++;
		int q = quadrante(atual, middle);
		point v = atual - atr[q]; // Vetor do atual em relação ao atrator
		v *= 2;
		v = v + atr[q];
		atual = v;
	}
	cout<<count<<endl;
}

int main(){
	int n; cin>>n;
	point p; cin>>p.x>>p.y;
	solve(n, p);
}