#include <bits/stdc++.h>
#define ld double
#define ll long long
using namespace std;

const int M = (int)1e9+7;

tuple<int, int, int> gcd(int a, int b) {
  if(b == 0) return make_tuple(a, 1, 0);
  int q, w, e;
  tie(q, w, e) = gcd(b, a % b);
  return make_tuple(q, e, w - e * (a / b));
}

inline ll mod(ll a){
	return (a%M + M)%M;
}

ll inverse_mod(int a){
	auto [g, x, y] = gcd(a, M);
	return mod(x);
}

vector<vector<ll>> mult(vector<vector<ll>> &A, vector<vector<ll>> &B){
	int n_r = A.size(), n_c = A[0].size();
	int m_r = B.size(), m_c = B[0].size(); // vou assumir que não terá nada de errado na passagem

	vector<vector<ll>> C(n_r, vector<ll>(m_c));

	for(int Ai = 0; Ai<n_r; Ai++){
		for(int Bj = 0; Bj < m_c; Bj++){
			for(int i = 0; i < n_c; i++){
				C[Ai][Bj] = (C[Ai][Bj] + A[Ai][i] * B[i][Bj])%M;
			}
		}
	}
	return C;
}

vector<vector<ll>> fast_pow(vector<vector<ll>> &A, int n){
	int An = A.size(), Am = A[0].size();
	vector<vector<ll>> res(An, vector<ll>(Am, 0));
	for(int i = 0; i<min(An, Am); i++) res[i][i] = 1;

	while(n){
		if(n & 1) res = mult(res, A);
		A = mult(A, A);
		n >>= 1;
	}
	return res;
}


vector<vector<ll>> markov_chain(vector<vector<ll>> &states, int initial_state, int m){
	vector<vector<ll>> initial_vector(1, vector<ll>(states[0].size(), 0));
	initial_vector[0][initial_state] = 1;
	vector<vector<ll>> states_pot = fast_pow(states, m);

	mult(initial_vector, states_pot);

	return mult(initial_vector, states_pot);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	auto t1 = std::chrono::high_resolution_clock::now();

	int n, m, k; cin>>n>>m>>k;
	vector<vector<ll>> state_matrix(5*n, vector<ll>(5*n, 0));

	for(int i = 0; i<m; i++){
		int u, v, t; cin>>u>>v>>t;
		u--; v--;
		u *= 5, v *= 5;
		state_matrix[u][v+t-1]++; // liga u com o dummy t de v. (possivelmente o próprio v)
		state_matrix[v][u+t-1]++; 
	}
	// liga os dummies
	for(int i = 0; i<n; i++){
		for(int t = 4; t >= 1; t--){
			state_matrix[5*i+t][5*i+t-1] = 1;
		}
	}
	
	for(int i = 0; i<n; i++){
		ll k = 0;
		for(int j = 0; j<5*n; j++) k += state_matrix[5*i][j];
		if(k == 0){
			k = 1, state_matrix[5*i][5*i] = 1;
		}

		int x = inverse_mod(k);
		for(int j = 0; j<5*n; j++){
			state_matrix[5*i][j] = mod(state_matrix[5*i][j]*x);
		}
	}

	for(int i = 0; i<5*n; i++){
		state_matrix[5*(n-1)][i] = 0;
	}
	state_matrix[5*(n-1)][5*(n-1)] = 1; 
	

	vector<vector<ll>> res = markov_chain(state_matrix, 0, k);
	cout<<res[0][5*(n-1)]<<endl;

	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	cerr << "Time taken: " << duration << " ms" << endl;

}