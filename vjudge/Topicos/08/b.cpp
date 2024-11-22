#include <bits/stdc++.h>
using namespace std;

enum {
	north = 0,
	east = 1,
	south = 2,
	west = 3
};

bool isValid(pair<pair<int, int>, pair<int, int>> &a, vector<vector<int>> &v, int i0, int j0){
	int i = a.first.first, j = a.first.second;
	if(i>0 && i<v.size()-1 && j>0 && j<v[0].size()-1){
		if(i0 == i && j0 == j) return true;
		else if(i0 == i) {
			if(j < j0){
				for(int k = j; k<j0; k++) if(v[i][k] == 1) return false;
			} else {
				for(int k = j0+1; k<=j; k++) if(v[i][k] == 1) return false;
			}
		} else {
			if(i < i0) {
				for(int k = i; k<i0; k++) if(v[k][j] == 1) return false;
			} else{
				for(int k = i0+1; k<=i; k++) if(v[k][j] == 1) return false;
			}
		}
		return true;
	}
	return false;
}

pair<int, int> nextPos(pair<int, int> p, int d, int k){
	if(d == north) return {p.first-k, p.second};
	else if(d == east) return {p.first, p.second+k};
	else if(d == south) return {p.first+k, p.second};
	else return {p.first, p.second-k};
}

void printaM(vector<vector<int>> &v, pair<int, int> &a){
	for(int i = 0; i<v.size(); i++){
		for(int j = 0; j<v[0].size(); j++){
			if(make_pair(i, j) == a) cout<<"X ";
			else cout<<v[i][j]<<" ";
		} cout<<endl;
	}cout<<endl;
}


int bfs(pair<int, int> a, pair<int, int> b, vector<vector<int>> &v, int d){
	if(a == b) return 0;
	queue<pair<pair<int, int>, pair<int, int>>> q;
	vector<vector<vector<bool>>> visitados(v.size(), vector<vector<bool>>(v[0].size(),
							vector<bool>(4, false)));
	q.push({a, {d, 0}});
	while(!q.empty()){
		auto p = q.front(); q.pop();
		if(p.first == b) {
			return p.second.second;
		}
		// cout<<p.first.first<<" "<<p.first.second<<" "<<p.second.first<<" "<<p.second.second<<endl;
		// printaM(v, p.first); cout<<endl;
		int i = p.first.first, j = p.first.second, d1 = p.second.first, p1 = p.second.second+1;
		vector<pair<pair<int, int>, pair<int, int>>> vizinhos;
		switch(d1){
			case north:
				vizinhos = {{{i, j}, {(d1+1)%4, p1}}, {{i, j}, {((d1-1)%4+4)%4, p1}},
				{{i-1, j}, {d1, p1}}, {{i-2, j}, {d1, p1}}, {{i-3, j}, {d1, p1}}};
				break;
			case east:
				vizinhos = {{{i, j}, {(d1+1)%4, p1}}, {{i, j}, {((d1-1)%4+4)%4, p1}},
				{{i, j+1}, {d1, p1}}, {{i, j+2}, {d1, p1}}, {{i, j+3}, {d1, p1}}};
				break;
			case south:
				vizinhos = {{{i, j}, {(d1+1)%4, p1}}, {{i, j}, {((d1-1)%4+4)%4, p1}},
				{{i+1, j}, {d1, p1}}, {{i+2, j}, {d1, p1}}, {{i+3, j}, {d1, p1}}};
				break;
			case west:
				vizinhos = {{{i, j}, {(d1+1)%4, p1}}, {{i, j}, {((d1-1)%4+4)%4, p1}},
				{{i, j-1}, {d1, p1}}, {{i, j-2}, {d1, p1}}, {{i, j-3}, {d1, p1}}};
				break;
		}
		for(auto e: vizinhos){
			if(isValid(e, v, i, j) && !visitados[e.first.first][e.first.second][e.second.first]){
				visitados[e.first.first][e.first.second][e.second.first] = true;
				// cout<<"vizinho: "<<e.first.first<<" "<<e.first.second<<" "<<e.second.first<<" "<<e.second.second<<endl;
				// printaM(v, e.first); cout<<endl;
				q.push(e);
			}
		}
	}
	return -1;
}

int main(){
	while(true){
		int a, b; cin>>a>>b;
		if(!a && !b) break;
		vector<vector<int>> matriz_init(a, vector<int>(b));
		for(int i = 0; i<a; i++){
			for(int j = 0; j<b; j++){
				cin>>matriz_init[i][j];
			}
		}
		vector<vector<int>> matriz(a+1, vector<int>(b+1, 0));
		for(int i = 0; i<=a; i++){
			for(int j = 0; j<=b; j++){
				if ((i < a && j < b && matriz_init[i][j] == 1) || 
					(i < a && j > 0 && matriz_init[i][j-1] == 1) || 
					(i > 0 && j < b && matriz_init[i-1][j] == 1) || 
					(i > 0 && j > 0 && matriz_init[i-1][j-1] == 1)) {
					matriz[i][j] = 1;
				} 
			} 
		}
		vector<vector<bool>> visitados(a+1, vector<bool>(b+1, false));
		pair<int, int> inicio, fim;
		cin>>inicio.first>>inicio.second>>fim.first>>fim.second;
		string dir; cin>>dir;
		// printaM(matriz, inicio);
		// cout<<endl;
		// printaM(matriz, fim);
		int d;
		if(dir == "north") d = north;
		if(dir == "east") d = east;
		if(dir == "south") d = south;
		if(dir == "west") d = west;

		int res = bfs(inicio, fim, matriz, d);
		cout<<res<<endl;
	}
}