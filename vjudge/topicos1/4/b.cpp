#include <bits/stdc++.h>
using namespace std;

int n, k; // n = primeira partição, k = segunda partição
vector<vector<int>> g; // Lista de adjecências da primeira partição para a segunda. 
// Escolher a menor delas como a primeira durante a leitura.
vector<int> mt;
vector<bool> used;

bool try_kuhn(int v) {
	if (used[v])
	return false;
	used[v] = true;
	for (int to : g[v]) {
		if (mt[to] == -1 || try_kuhn(mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}

int main(){
	cin>>n>>k;
	g.assign(n, vector<int>());

	for(int i = 0; i<n; i++){
		int c; cin>>c;
		for(int j = 0; j<c; j++){
			int d; cin>>d;
			g[i].push_back(d-1);
		}
	}

	mt.assign(k, -1);
	vector<bool> used1(n, false);
	for (int v = 0; v < n; ++v) {
		for (int to : g[v]) {
			if (mt[to] == -1) {
				mt[to] = v;
				used1[v] = true;
				break;
			}
		}
	}
	for (int v = 0; v < n; ++v) {
		if (used1[v])
			continue;
		used.assign(n, false);
		try_kuhn(v);
	}
	
	int res = 0;
	for (int i = 0; i < k; ++i)
		if (mt[i] != -1)
			res++;
	cout<<res<<endl;
}