#include <bits/stdc++.h>
#define ll long long
#define all(v) v.begin(), v.end()
#define vc vector
using namespace std;


void floyd_warshall(vc<vc<int>> &adj, vc<vc<bool>> &v){
	int n = adj.size();
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			for(int k = 0; k<n; k++){
				if(i == j || i == k || j == k) continue;
				if(adj[i][k]+adj[k][j] <= adj[i][j]){
					adj[i][j] = adj[i][k]+adj[k][j];
					v[i][j] = true;
				}
			}
		}
	}
}


int main(){

	int n; cin>>n;
	vc<vc<int>> adj(n, vc<int>(n));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++)
			cin>>adj[i][j];
	}
	vc<vc<int>> n_adj = adj;
	vc<vc<bool>> aux(n, vc<bool>(n, false));
	
	floyd_warshall(n_adj, aux);
	

	int c = 0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(n_adj[i][j] < adj[i][j]){
				cout<<-1<<endl;
				return 0;
			} else if(n_adj[i][j] == adj[i][j] && aux[i][j]) c++;
		}
	}

	cout<<c/2<<endl;

}