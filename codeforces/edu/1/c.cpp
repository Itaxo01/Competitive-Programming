#include <bits/stdc++.h>
using namespace std;

struct point{
	int x, y;
	point(int a = 0, int b = 0){
		x = a;
		y = b;
	}
};

int quad(point a) {
	if(a.x >= 0) {
		if(a.y >= 0) return 1;
		return 3;
	}
	if(a.y >= 0) return 2;
	return 4;
}

point axis = {0, 0};

bool cmp(point a, point b){
	int q1 = quad(a), q2 = quad(b);
	if(q1 != q2) return q1 < q2;
	int cross = a.x*b.y - b.x*a.y;
	return cross > 0;
}

double mag(point a){
	return sqrt(a.x*a.x + a.y*a.y);
}

double angle(point a, point b){
	double dot = a.x*b.x + a.y*b.y;
	double m = mag(a) * mag(b);
	return acos(dot/m);
}

signed main(){
	int n; cin>>n;
	vector<point> v(n);
	for(int i = 0; i<n; i++){
		int a, b; cin>>a>>b;
		v[i] = {a, b};
	}
	sort(v.begin(), v.end(), cmp);

	double menor = angle(v[0], v[1]);
	vector<int> menores = {0, 1};
	for(int i = 1; i<n-1; i++){
		double ang = angle(v[i], v[i+1]);
		cout<<ang<<endl;
		if(ang < menor){
			menor = ang;
			menores[0] = i; menores[1] = i+1;
		}
	}
	double ang = angle(v[n-1], v[0]);
	if(ang < menor){
		menor = ang;
		menores[0] = n-1; menores[1] = 0;
	}
	sort(menores.begin(), menores.end());
	cout<<menores[0]+1<<" "<<menores[1]+1<<endl;
}