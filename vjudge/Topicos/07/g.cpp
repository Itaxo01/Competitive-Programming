#include <bits/stdc++.h>
using namespace std;

bitset<201> visited;
vector<bool> color(201);
bool res = true;

void dfs(int a, vector<vector<int>> &v, int pai, int &cor0, int &cor1){
	visited.set(a);
	if(pai!=-1){
		color[a] = !color[pai];
		color[a] ? cor1++ : cor0++;
	}
	else{
		cor0++;
	}
	for(int e: v[a]){
		if(!visited.test(e)){
			dfs(e, v, a, cor0, cor1);
		} else{
			if(color[e] == color[a])
				res = false;
		}
	}
}

int main(){
	int tt; cin>>tt;
	while(tt--){
		int a, b; cin>>a>>b;
		vector<vector<int>> adj(a);
		for(int i = 0; i<b; i++){
			int c, d; cin>>c>>d;
			adj[c].push_back(d);
			adj[d].push_back(c);
		}

		visited.reset();
		color.clear();
		res = true;

		int cor = 0;
		for(int i = 0; i<a; i++){
			int cor1 = 0, cor2 = 0;
			if(!visited.test(i)){
				dfs(i, adj, -1, cor1, cor2);
			}
			(cor1 && !cor2) || (!cor1 && cor2) ? cor++ : cor;
			cor+=min(cor1, cor2);
		}
		if(!res) cout<<-1<<endl;
		else cout<<cor<<endl;
	}
}