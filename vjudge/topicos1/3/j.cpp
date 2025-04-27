#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

int n, m;
struct point{
	int x, y; int label;
	point(){}
	point(int x, int y, int l = -1): x(x), y(y), label(l){}
	static point origin;
	int static quadrante(const point &p){
		if(p.y == 0 && p.x < n) return 1;
		if(p.x == n && p.y < m) return 2;
		if(p.y == m && p.x > 0) return 3;
		if(p.x == 0 && p.y > 0) return 4;
		return -1;
	}
    friend point operator - (const point p, const point q) { 
		return point(p.x - q.x, p.y - q.y);  }
		static bool rotation_cmp(const point&p, const point&q){
			int q1 = quadrante(p), q2 = quadrante(q);
			if(q1 != q2) return q1<q2;
			if(q1 == 1) return p.x < q.x;
			if(q1 == 2) return p.y < q.y;
			if(q1 == 3) return p.x > q.x;
			if(q1 == 4) return p.y > q.y;
			return false;
		}
		friend ostream& operator<<(ostream& os, const point& p) {
			os << p.x << ", " << p.y;
		return os;
	}
};
point point::origin(0, 0);

bool dangerous(point a, point b){
	if(((a.x == 0 || a.x == n) || (a.y == 0 || a.y == m)) &&
		((b.x == 0 || b.x == n) || (b.y == 0 || b.y == m)))
			 return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int q; cin>>q;
	// jogo similar ao "Connect dots", porém a espessura das linhas aqui é desconsiderável. Dessa forma
	// acredito que sempre haja solução. a não ser que dois pares de pontos estejam localizados nas bordas do papel

	// se dois pares de pontos estão de tal forma que sua ordem seja P1 P2 P1 P2, não há solução
	vector<point> v;
	for(int i = 0; i<q; i++){
		int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
		point a(x1, y1, i), b(x2, y2, i);
		if(dangerous(a, b)) {
			v.push_back(a);
			v.push_back(b);
		}
	}
	sort(v.begin(), v.end(), point::rotation_cmp);
	unordered_map<int, int> m;
	vector<int> st;
	for(int i = 0; i<v.size(); i++){
		int e = v[i].label;
		if(m.find(e) != m.end()){
			if(e != st.back()){
				cout<<"N"<<endl;
				return 0;
			} else{
				st.pop_back();
			}
		} else {
			st.push_back(e);
			m[e]++;
		}
	}

	cout<<"Y"<<endl;
}