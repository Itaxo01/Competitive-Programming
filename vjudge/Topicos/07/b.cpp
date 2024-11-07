#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> &v){
	multiset<int> s;
	for(int i = 0; i<v.size(); i++){
		auto it = s.lower_bound(v[i]);
		if (it != s.end()) s.erase(it);
		s.insert(v[i]);
	}
	return s.size();
}

void dfs(int a, vector<vector<int>> &v, vector<int> &lis_,
		 vector<bool> &visitados, vector<int> &w, 
		 vector<int> &caminho) {
    visitados[a] = true;
	 caminho.push_back(w[a]);
	 lis_[a] = lis(caminho);
    for (int e : v[a]) {
        if (!visitados[e]) {
            dfs(e, v, lis_, visitados, w, caminho);
        }
    }
	 caminho.pop_back();
}


signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cout.tie(0);
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
	vector<int> caminho;

	vector<int> lis_(a);
	dfs(0, adj, lis_, visitados, w, caminho);

	for(int i = 1; i<a; i++){
		if(i==1) cout<<lis_[i];
		else cout<<" "<<lis_[i];
	}
	cout<<endl;
}