#include <bits/stdc++.h>

using namespace std;
int p[200001];
char color[200001];
int val[200001];
bitset<200001> visited;


void dfs(int src, int& count){
	visited[src-1] = 1;
	if(color[src-1]=='0') count++;
	if(visited[p[src-1]-1] == 0){
		dfs(p[src-1], count);
	}
	val[src-1] = count;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin>>n;
	for(int i = 0; i<n; i++){
		int p1; cin>>p1;
		for(int j = 0; j<p1; j++){
			cin>>p[j];
		}
		for(int j = 0; j<p1; j++){
			cin>>color[j];
		}
		int group = 0;
		bool first = true;
		visited.reset();
		for(int j = 0; j<p1; j++){
			int co= 0;
			if(visited[p[j]-1] == 0) dfs(p[j], co);
			else{
				co = val[p[j]-1];}
			if(first){
				cout<<co;
				first = false;}
			else cout<<" "<<co;
		}
		cout<<endl;
	}
}