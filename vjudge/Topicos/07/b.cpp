#include <bits/stdc++.h>
using namespace std;

inline int lis(int v, vector<int> &s){
	auto it = lower_bound(s.begin(), s.end(), v)-s.begin();
	if(it<s.size()) s[it] = v;
	else s.push_back(v);
	return s.size();
}

void dfs(int a, vector<vector<int>> &v, vector<int> &lis_,
		 vector<bool> &visitados, vector<int> &w, vector<int> s) {
    visitados[a] = true;
	lis_[a] = lis(w[a], s);
    for (int e : v[a]) {
        if (!visitados[e]) {
            dfs(e, v, lis_, visitados, w, s);
        }
    }
}


signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int a; cin>>a;
	vector<vector<int>> adj(a);
	for(int i = 0; i<a-1; i++){
		int b; cin>>b; --b;
		adj[b].push_back(i+1);
		adj[i+1].push_back(b);
	}

	vector<int> w(a);
	for(int i = 0; i<a; i++){
		cin>>w[i];
	}

	vector<bool> visitados(a, false);
	
	vector<int> lis_(a);
	vector<int> s;
	dfs(0, adj, lis_, visitados, w, s);

	for(int i = 1; i<a; i++){
		if(i==1) cout<<lis_[i];
		else cout<<" "<<lis_[i];
	}
	cout<<endl;
}