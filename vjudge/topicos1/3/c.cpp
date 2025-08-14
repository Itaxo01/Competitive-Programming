#include <bits/stdc++.h>
using namespace std;

struct point{
	int x, y;
	point(){}
	point(int x, int y): x(x), y(y) {}
};

struct cloud{
	int dir; // direction: 0 - N, 1 - S, 2 - E, 3 - W
	vector<point> vertices; // sorted clockwise
	cloud(){}
	cloud(char c, int n){
		if(c == 'N') dir = 0;
		else if(c == 'S') dir = 1;
		else if(c == 'E') dir = 2;
		else dir = 3;
		vertices.assign(n, point());
	}
};

point inicio, fim;
vector<cloud> nuvens;
int n;



int solve(){
	// Para cada X, Y de inicio em direção ao fim, vou guardar o tempo mínimo
	
}

void build(){
	int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
	inicio = point(x1, y1), fim = point(x2, y2);
	int n; cin>>n;
	nuvens.assign(n, cloud());
	for(int i = 0; i<n; i++){
		char C; int V;
		cin>>C>>V;
		nuvens[i] = cloud(C, V);
		for(int j = 0; j<V; j++){
			int x, y; cin>>x>>y;
			nuvens[i].vertices[j] = point(x, y);
		}
	}

}

int main(){
	build();
	cout<<solve()<<endl;
}