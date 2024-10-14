#include <bits/stdc++.h>
#define ll long long

using namespace std;
int a;


bool checkValid(vector<pair<int, int>> p){
	for(auto e:p){
		if(e.first<0 || e.first>=2 || e.second<0 || e.second>=a)
			return false;
	}
	return true;
}

int dfs(vector<vector<char>> &v, vector<vector<bool>> &usados){
	int i = 0, j = 0;
	int votos = 0;
	vector<vector<pair<int, int>>> groups =
			  {{{i, j}, {i+1, j}, {i, j+1}},
			  {{i, j}, {i, j-1}, {i+1, j}},
			  {{i, j}, {i-1, j}, {i-1, j+1}},
			  {{i, j}, {i-1, j}, {i-1, j-1}},
			  {{i, j}, {i+1, j}, {i+2, j}},
			  {{i, j}, {i-1, j}, {i+1, j}},
			  {{i, j}, {i-1, j}, {i-2, j}}};
	for(auto e:groups){
		if(checkValid(e)){
			int saldo = 0;
			for(auto k:e){
				if(v[k.first][k.second]=='A'){
					saldo++;
				}
			}
			if(saldo==2){
				votos++;
				for(auto k:e){
					usados[k.first][k.second] = true;
				}
			}
		}
	}
}

int main(){
	int n; cin>>n;
	while(n--){
		cin>>a;
		vector<vector<char>> v(2, vector<char>(a));
		vector<vector<bool>> usados(2, vector<bool>(a));
		for(int i = 0; i<a; i++){
			cin>>v[0][i];
		}
		for(int i = 0; i<a; i++){
			cin>>v[1][i];
		}
		int votos = 0;
		int saldo = 0;
	}
}