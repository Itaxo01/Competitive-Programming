#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int parent, vector<vector<int>> &adj, vector<int> &disc,
 vector<int> &low, vector<bool> &visited, vector<bool> &crit, int &t) {
    visited[u] = true;
    t++;
    disc[u] = low[u] = t;
    int children = 0;

    for (int v : adj[u]) {
        if (!visited[v]) {
            children++;
            dfs(v, u, adj, disc, low, visited, crit, t);

            low[u] = min(low[u], low[v]);

            if (parent != -1 && low[v] >= disc[u]) {
                crit[u] = true;
            }

            if (parent == -1 && children > 1) {
                crit[u] = true;
            }
        } else if (v != parent) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int solve(int n, vector<vector<int>> &adj) {
    vector<int> disc(n, -1), low(n, -1);
    vector<bool> visited(n, false), crit(n, false);
    int t = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, -1, adj, disc, low, visited, crit, t);
        }
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (crit[i]) {
            count++;
        }
    }

    return count;
}

int main(){
	while(true){
		int a; cin>>a;
		if(!a) break;
        string lixo;
        getline(cin, lixo);
		vector<vector<int>> adj(a);
		while(true){
			string s; getline(cin, s);
			stringstream ss(s);
			int e; ss>>e;
            if(!e) break;
            int k;
            while(ss>>k){
                adj[e-1].push_back(k-1);
                adj[k-1].push_back(e-1);
            }

		}
        cout<<solve(a, adj)<<endl;
	}
}