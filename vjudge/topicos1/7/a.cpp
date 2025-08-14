#pragma optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, m; cin>>n>>m;
	vector<vector<pair<int, char>>> in(n), out(n);
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	queue<pair<int, int>> q;
	for(int i = 0; i<m; i++){
		int u, v; char c;
		cin>>u>>v>>c;
		u--; v--;
		if(!visited[u][v]) q.push({u, v});
		visited[u][v] = true;
		in[v].push_back({u, c});
		out[u].push_back({v, c});
	}
	for(int i = 0; i<n; i++){
		if(!visited[i][i]){
			visited[i][i] = true;
			q.push({i, i});
		}
	}

	while(!q.empty()){
		auto [u, v] = q.front(); q.pop();
		for(auto [a, c1] : in[u]){
			for(auto [b, c2] : out[v]){
				if(c1 == c2 && !visited[a][b]){
					visited[a][b] = true;
					q.push({a, b});
				}
			}
		}
	}

	int res = 0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(visited[i][j] && i != j) res++;
		}
	}
	cout<<res<<endl;

}