#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>> &v, int i, int j){
	return (i >= 0 && i < v.size() && j >= 0 && j < v[0].size());
}

void dfs(vector<vector<char>> &v, vector<vector<int>> &visitados, int i, int j){
	int count = 0;
	stack<pair<int, int>> s;
	s.push({i, j});
	vector<pair<int, int>> remember;
	remember.push_back({i, j});
	visitados[i][j] = 0;
	while(!s.empty()){
		int i = s.top().first, j = s.top().second; s.pop();
		vector<pair<int, int>> vizinhos = {{i+1, j}, {i-1, j}, {i, j-1}, {i, j+1}};
		for(auto e: vizinhos){
			i = e.first, j = e.second;
			if(isValid(v, i, j)){
				if(v[i][j] == '*') count++;
				else if(visitados[i][j] == -1) {
					remember.push_back(e);
					visitados[i][j] = 0;
					s.push(e);
				}
			}
		}
	}
	for(auto e: remember){
		visitados[e.first][e.second] = count;
	}
}

int main(){
	int a, b, c; cin>>a>>b>>c;
	vector<vector<char>> v(a, vector<char>(b));
	vector<vector<int>> visitados(a, vector<int>(b));

	for(int i = 0; i<a; i++){
		for(int j = 0; j<b; j++){
			cin>>v[i][j];
			visitados[i][j] = -1;
		}
	}

	for(int t = 0; t<c; t++){
		int i, j; cin>>i>>j;
		i--; j--;
		if(visitados[i][j] == -1)
			dfs(v, visitados, i, j);

		cout<<visitados[i][j]<<endl;
		
	}
}