#include <bits/stdc++.h>
using namespace std;


signed main(){
	// Ideia da IA, não digeri muito ainda e não vi o editorial
	// supus que fosse matching máximo em um grafo ordinário, porém isto é NP-hard
	// a IA me trouxe a informação de que de fato está relacionado, porém o problema involve o set máximo independente
	// que é equivalente a n - min_vertex_matching. Ambos são NP-hard

	// Então a solução envolve achar o máximo clique no complementar do grafo
	int n; cin>>n;
	vector<vector<bool>> matriz(n, vector<bool>(n));
	for(int i =0 ; i<n; i++){
		for(int j = 0; j<n; j++){
			int k; cin>>k;
			matriz[i][j] = k;
		}
	}
	vector<vector<bool>> matriz_c(n, vector<bool>(n));
	for(int i =0 ; i<n; i++){
		for(int j = 0; j<n; j++){
			matriz_c[i][j] = !matriz[i][j];
		}
	}
}