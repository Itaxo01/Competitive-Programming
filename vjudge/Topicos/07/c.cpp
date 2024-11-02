#include <bits/stdc++.h>
using namespace std;
bitset<101> visited[101];

bool valid(pair<int, int> a, int n, int m){
	return (a.first>=0 && a.first<n && a.second>=0 && a.second<m);
}

void dfs(int i, int j, vector<string> &m, int &res){
	if(m[i][j] == 'W') {
		res++;
		visited[i].set(j);
		vector<pair<int, int>> vizinhos = {{i-1, j}, {i+1, j}, {i, j-1}, {i, j+1},
								{i-1, j-1}, {i-1, j+1}, {i+1, j-1}, {i+1, j+1}};
		for(auto e: vizinhos){
			if(valid(e, m.size(), m[0].size()) && !visited[e.first].test(e.second)){
				if(m[e.first][e.second] == 'W'){
					dfs(e.first, e.second, m, res);
				}
			}
		}
	}
}

int main(){
	int a; cin>>a;
	string s;
	getline(cin, s);
	getline(cin, s);
	bool first = true;
	while(a--){
		if(!first) cout<<endl;
		vector<string> matriz;
		while(getline(cin, s)){
			if(s[0]-'0'>=0  && s[0]-'0'<=9) break;
			matriz.push_back(s);
		}
		while(s.size()>1){
			for(int i = 0; i<101; i++) visited[i].reset();
			stringstream ss(s);
			int a; ss>>a;
			int b; ss>>b;
			int res = 0;
			dfs(a-1, b-1, matriz, res);
			cout<<res<<endl;
			if(!getline(cin, s)) break;;
		}
		first = false;
	}
}