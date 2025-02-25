#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int num(char e){
	if(e >= 'a' && e <= 'z')
		return (int)(e-'a');
	return (int)(e-'1');
}

bool is_valid(ii &e){
	int i = e.first, j = e.second;
	return (i >= 0 && i < 8 && j >= 0 && j < 8);
}

void make_graph(vector<vector<int>> &g){
	for(int i = 0; i<8; i++){
		for(int j = 0; j<8; j++){
			int pos = i*8+j;
			vector<ii> vizinhos = {
				{i+2, j+1}, {i+2, j-1}, {i-2, j+1}, {i-2, j-1},
				{i+1, j+2}, {i-1, j+2}, {i+1, j-2}, {i-1, j-2}
			};
			for(auto e: vizinhos){
				if(is_valid(e)){
					g[pos].push_back(e.first*8+e.second);
				}
			}
		}
	}
}

int bfs(int a, int b, vector<vector<int>> &g){
	vector<bool> visitados(64, false);
	queue<ii> q; q.push({a, 0});
	visitados[a] = true;
	while(!q.empty()){
		auto p = q.front(); q.pop();
		if(p.first == b) return p.second;
		for(auto e: g[p.first]){
			if(!visitados[e]) {
				visitados[e] = true;
				q.push({e, p.second+1});
			}
		}
	}
	return -1;
}

int main(){
	string a, b;
	vector<vector<int>> g(64);
	make_graph(g);
	

	while(cin>>a>>b){
		ii p1, p2;
		p1.first = num(a[0]), p1.second = num(a[1]);
		p2.first = num(b[0]), p2.second = num(b[1]);
		int p = p1.first*8+p1.second;
		int q = p2.first*8+p2.second;

		cout<<"To get from "<<a<<" to "<<b<<" takes "<<bfs(p, q, g)<<" knight moves.\n";
	}
}