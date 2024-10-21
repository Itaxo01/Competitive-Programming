#include <bits/stdc++.h>

using namespace std;

bool checkValid(pair<int, int> e, vector<vector<char>> &v){
	if(e.first>=0 && e.second>=0 && e.first<v.size() && e.second<v[0].size()){
		return true;
	} return false;
}

void dfs(vector<vector<char>> &v){
	int i = 0, j = 0;
	while(v[i][j]!='#'){
		j++;
		if(j==v[0].size()){
			i++; j = 0;
		}
	}
	pair<int, int> mmx = {j, j};
	pair<int, int> mmy = {i, i};
	

	stack<pair<int, int>> s;
	s.push({i, j});
	while(!s.empty()){
		v[i][j] = '.';
		i = s.top().first; j = s.top().second;
		s.pop();
		pair<int, int> vizinhos[4] = {{i+1, j}, {i-1, j}, {i, j+1}, {i, j-1}};
		for(auto e: vizinhos){
			if(checkValid(e, v)){
				if(v[e.first][e.second] == '#'){
					if(e.first<mmy.first)
						mmy.first = e.first;
					if(e.first > mmy.second)
						mmy.second = e.first;
					if(e.second < mmx.first)
						mmx.first = e.second;
					if(e.second > mmx.second)
						mmx.second = e.second;
					s.push(e);
				}
			}
		}
	}
	cout<<1+(mmy.first+mmy.second)/2<<" ";
	cout<<1+(mmx.first+mmx.second)/2<<endl;
	
}

void work(){
	int a, b; cin>>a>>b;
	vector<vector<char>> v(a, vector<char>(b));
	for(int i = 0; i<a; i++){
		for(int j = 0; j<b; j++){
			cin>>v[i][j];
		}
	}
	
	dfs(v);
}

int main(){
	int n; cin>>n;
	while(n--){
		work();
	}
}