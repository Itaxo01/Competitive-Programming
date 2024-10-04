#include <bits/stdc++.h>
using namespace std;


char v[1000][1000];
int a, b;

bool check_valid(pair<int, int> pos){
	int i = pos.first, j = pos.second;
	if(i<0 or i>=a) return false;
	if(j<0 or j>=b) return false;
	if(v[i][j] == '#') return false;
	return true;
}
bool check_trap(vector<pair<int, int>> adj){
	for(auto e:adj){
		int i = e.first, j = e.second;
		if(check_valid(e)) if(v[i][j]=='T') return false;
	}
	return true;
}

void dfs(pair<int, int> pos, int &soma){
	int i = pos.first, j = pos.second;
	if(isdigit(v[i][j])){
		soma+= v[i][j]-'0';
	}
	v[i][j] = '#';
	vector<pair<int, int>> adj = {{i+1, j}, {i-1, j}, {i, j+1}, {i, j-1}};
	if(check_trap(adj)){
		for(auto vizinho:adj){
			if(check_valid(vizinho)) dfs(vizinho, soma);
		}
	}
}


int main(){
	while(cin>>a>>b){
		pair<int, int> pos;
		for(int i = 0; i<a; i++){
			for(int j = 0; j<b; j++){
				cin>>v[i][j];
				if(v[i][j]=='S') pos = {i, j};
			}
		}
		int soma = 0;
		dfs(pos, soma);
		cout<<soma<<endl;
	}
	return 0;
}