#include <bits/stdc++.h>

using namespace std;

bool checkWin(vector<vector<int>> v){
	int anterior = 0;
	for(auto e:v){
		for(int k:e){
			if(k!=0){
				if(k!=anterior+1) return false;
			}
		}
	}
	return true;
}

bool checkValid(pair<int, int> a){
	if(a.first>=0 and a.first<3 and a.second>=0 and a.second<3) return true;
	return false;
}
void solve(vector<vector<int>> v, set<vector<vector<int>>> &s, int counter, int &menor, pair<int, int> pos_0){
	if(checkWin(v)){
		if(counter<menor) menor = counter;
		return;
	}
	s.insert(v);
	int i = pos_0.first;
	int j = pos_0.second;
	pair<int, int> vizinhos[4] = {{i+1, j}, {i-1, j}, {i, j+1}, {i, j-1}};
	for(auto e:vizinhos){
		if(checkValid(e)){
			vector<vector<int>> v1 = v;
			int temp = v1[e.first][e.second];
			v1[e.first][e.second] = 0;
			v1[i][j] = temp;
			if(s.find(v1)==s.end()){
				solve(v, s, counter+1, menor, e);
			}
		}
	}

}

int main(){
	vector<vector<int>> v(3);
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			v[i].push_back(i*3+j);
		}
	}
	pair<int, int> pos = {0, 0};
	set<vector<vector<int>>> s;
	int menor = 0;
	solve(v, s, 0, menor, pos);
	
	cout<<menor<<endl;


}