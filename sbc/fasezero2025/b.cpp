#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
vector<vector<pair<int, char>>> adj;
char s[MAXN];
int pi[MAXN], it = 0, maior = 0;
void dfs(int v, int p, int n, int d){
	for(auto &e: adj[v]){
		int u = e.first; 
		if(u == p) continue;
		char c = e.second;
		int k = n;
		while(k > 0 && s[k] != c){
			k = pi[k-1];
			it++;
			if(it > 1e7) {
				maior = max(maior, 1); return;
			}
		}
		if(d && s[k] == c) k++;
		
		pi[d] = k;
		s[d] = c;
		
		int l = d+1;
		int pd = l - k;
		if (pd && pd != l && l % pd == 0) {
			maior = max(maior, pd);
		}
		dfs(e.first, v, k, d+1);
	}
}

int main(){
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n; cin>>n;
	adj.resize(n);
	for(auto &e: adj){
		e.reserve(2);
	}
	vector<int> v(n), P(n);
	for(int i = 0; i<n-1; i++){
		cin>>P[i]; P[i]--;
	}
	string s_; cin>>s_;
	
	for(int i = 0; i<n-1; i++){
		adj[P[i]].emplace_back(i+1, s_[i]);
	}
	dfs(0, -1, 0, 0);
	cout<<maior<<endl;
}