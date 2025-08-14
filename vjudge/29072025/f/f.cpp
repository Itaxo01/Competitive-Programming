#include <bits/stdc++.h>
// #define ld double
#define ll long long
using namespace std;

// int M = (int)1e9+7;
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

struct Matrix{
	vector<vector<ll>> m;
	int r, c;
	Matrix(int r, int c): r(r), c(c), m(r, vector<ll>(c, 0)) {};

	static Matrix I(int n){
		Matrix I(n, n);
		for(int i = 0; i<n; i++){
			I.m[i][i] = 1;
		}
		return I;
	}

	vector<ll> & operator[](int i){
		return m[i];
	}
	
	Matrix operator*(Matrix& B) {
		Matrix result(r, B.c);
		for(int i = 0; i<r; i++){
			for(int j = 0; j<B.c; j++){
				for(int k = 0; k<c; k++){
					result[i][j] = (result[i][j] + m[i][k] * B[k][j])%M;
				}
			}
		}
		return result;
	}

	Matrix fast_pow(int n){
		Matrix res = Matrix::I(r);
		while(n){
			if(n & 1) res = res*(*this);
			*this = (*this) * (*this);
			n >>= 1;
		}
		// *this = res;
		return res;
	}
};

Matrix markov_chain(Matrix &states, int initial_state, int m){
	Matrix initial_vector(1, states[0].size());
	initial_vector[0][initial_state] = 1;
	
	states = states.fast_pow(m);

	return initial_vector*states;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, m, k; cin>>n>>m>>k;
	Matrix state_matrix(5*n, 5*n);

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
	


	Matrix res = markov_chain(state_matrix, 0, k);
	cout<<res[0][5*(n-1)]<<endl;


}