#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int k, vector<vector<vector<char>>> &v){
	return (i>=0 && j>=0 && k>=0 && i<v.size() && j<v[0].size() && k<v[0][0].size());
}

vector<pair<pair<int, int>, int>> vizinhos(int i, int j, int k){
	vector<pair<pair<int, int>, int>> vs;
	vs = {{{i+1, j}, k}, {{i-1, j}, k}, {{i, j+1}, k},
		 {{i, j-1}, k}, {{i, j}, k+1}, {{i, j}, k-1}};
	return vs;
}

int bfs(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b,
				 int res, vector<vector<vector<char>>> &v){
	if(a == b) return 0;
	vector<vector<vector<bool>>> 
		visitados(v.size(), vector<vector<bool>>(v[0].size(), vector<bool>(v[0][0].size(), false)));
	
	queue<pair<pair<pair<int, int>, int>, int>> q;
	q.push({a, 0});
	visitados[a.first.first][a.first.second][a.second] = true;

	while(!q.empty()){
		auto p = q.front();
		if(p.first == b) return p.second;
		q.pop();
		int i = p.first.first.first, j = p.first.first.second, k = p.first.second;
		
		auto vs = vizinhos(i, j, k);

		for(auto e: vs){
			int i = e.first.first, j = e.first.second, k = e.second;
			if(isValid(i, j, k, v) && !visitados[i][j][k] && v[i][j][k] != '#'){
				visitados[i][j][k] = true;
				q.push({{{i, j}, k}, p.second+1});
			}
		}
	}
	return -1;
}

int main(){
	while(true){
		int a, b, c; cin>>a>>b>>c;
		if(!a && !b && !c) break;

		vector<vector<vector<char>>> matriz(a, vector<vector<char>>(b, vector<char>(c)));
		pair<pair<int, int>, int> inicio, fim;
		for(int i = 0; i<a; i++){
			for(int j = 0; j<b; j++){
				for(int k = 0; k<c; k++){
					cin>>matriz[i][j][k];
					if(matriz[i][j][k] == 'S') inicio = {{i, j}, k};
					if(matriz[i][j][k] == 'E') fim = {{i, j}, k};
				}
			}
		}
		int res = bfs(inicio, fim, 0, matriz);
		if(res == -1) cout<<"Trapped!"<<endl;
		else cout<<"Escaped in "<<res<<" minute(s)."<<endl;
	}
}