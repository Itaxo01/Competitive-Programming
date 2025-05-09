// Algoritmo do cp algorithms
#include <bits/stdc++.h>
#define int long long
#define INF INT_MAX
using namespace std;

int hungarian(vector<vector<int>> &A){
	int n = A.size()-1, m = A[0].size()-1; // For some reason, the cp algorithm uses 1-index
	vector<int> u (n+1), v (m+1), p (m+1), way (m+1);
	for (int i=1; i<=n; ++i) {
		p[0] = i;
		int j0 = 0;
		vector<int> minv (m+1, INF);
		vector<bool> used (m+1, false);
		do {
			used[j0] = true;
			int i0 = p[j0],  delta = INF,  j1;
			for (int j=1; j<=m; ++j)
				if (!used[j]) {
					int cur = A[i0][j]-u[i0]-v[j];
					if (cur < minv[j])
						minv[j] = cur,  way[j] = j0;
					if (minv[j] < delta)
						delta = minv[j],  j1 = j;
				}
			for (int j=0; j<=m; ++j)
				if (used[j])
					u[p[j]] += delta,  v[j] -= delta;
				else
					minv[j] -= delta;
			j0 = j1;
		} while (p[j0] != 0);
		do {
			int j1 = way[j0];
			p[j0] = p[j1];
			j0 = j1;
		} while (j0);
	}
	return -v[0];
}


signed main(){
	int n; cin>>n;
	vector<vector<int>> m(n+1, vector<int>(n+1));
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			cin>>m[i][j];
		}
	}

	// Vou ter uma matriz n x n, onde uma das dimensões será os (n+1)/2 vértices impares, 1, 3, 5 etc
	// e a outra será as (n+1)/2 posições em que se poderá colocar o vértice. O valor da matriz[i][j] será o
	// custo de utilizar o vértice i como ponte entre os vértices j*2 e j*2 + 1.
	vector<vector<int>> hungaro(1 + (n+1)/2, vector<int>(1 + (n+1)/2));
	for(int i = 1; i<=(n+1)/2; i++){
		int vi = 2*i - 1; // impar
		for(int j = 1; j<=(n+1)/2; j++){
			int vj1 = j*2 - 2, vj2 = j*2;
			// par anterior e par posterior
			int sum = (j > 1 ? m[vi][vj1] : 0) + (vj2 <= n ? m[vi][vj2] : 0);
			hungaro[i][j] = sum;
		}
	}
	cout<<hungarian(hungaro)<<endl;
}