#include <bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>> &adj, vector<int> &root, vector<int> &group, vector<int> &peso){
	stack<int> s;
	for(int e:root) s.push(e);
	
	while(!s.empty()){
		int u = s.top();
		s.pop();
		group.push_back(u);
		for(int v:adj[u]){
			peso[v]--;
			if(peso[v]==0) s.push(v);
		}
	}
}

int main(){
	while(true){
		int a, b; cin>>a>>b;
		if(!a && !b) break;
		vector<vector<int>> vadj(a);
		vector<int> peso(a, 0);
		for(int i = 0; i<b; i++){
			int c, d; cin>>c>>d;
			vadj[c-1].push_back(d-1);
			peso[d-1]++;
		}

		vector<int> roots;
		for(int i = 0; i<a; i++){
			if(peso[i]==0){
				roots.push_back(i);
			}
		}

		vector<int> group;
		dfs(vadj, roots, group, peso);

		if(group.size()!=a)
			cout<<"IMPOSSIBLE"<<endl;
		else{
			for(int e:group){
				cout<<e+1<<endl;
			}
		}
	}
}