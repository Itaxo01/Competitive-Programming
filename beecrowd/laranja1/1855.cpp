#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

bool in_boundary(int i, int j, vector<vector<char>> &v){
	return (i>=0 && j>=0 && i<v.size() && j<v[0].size());
}

bool is_valid(vector<vector<char>> &v){
	vector<vector<vector<bool>>> visitado(v.size(), vector<vector<bool>>(v[0].size(), vector<bool>(4, false)));
	
	int d = 0;
	ii pos = {0, 0};
	while(true){
		int i = pos.first, j = pos.second;
		if(visitado[i][j][d]) return false;
		visitado[i][j][d] = true;

		if(v[i][j] == '*') return true;
		if(v[i][j] != '.') {
			if(v[i][j] == '>') d = 0;
			if(v[i][j] == '<') d = 1;
			if(v[i][j] == '^') d = 2;
			if(v[i][j] == 'v') d = 3;
		}
		if(d == 0) pos.second++;
		else if(d == 1) pos.second--;
		else if(d == 2) pos.first--;
		else if(d == 3) pos.first++;
		
		if(!in_boundary(pos.first, pos.second, v)) return false;
	}

}

int main(){
	int a, b; cin>>b>>a;
	vector<vector<char>> v(a, vector<char>(b));
	for(int i = 0; i<a; i++){
		for(int j = 0; j<b; j++){
			cin>>v[i][j];
		}
	}

	if(is_valid(v)) cout<<"*\n";
	else cout<<"!\n";
}