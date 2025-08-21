// #pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;


struct game_matrix{
	int n;
	vector<vector<bool>> v;
	vector<vector<bool>> locked;
	vector<ull> pot;
	unordered_map<ull, int> mem;

	int di[8] = {1, -1, 0, 0, 1, 1, -1, -1};
	int dj[8] = {0, 0, 1, -1, 1, -1, 1, -1}; // vizinhos
	
	game_matrix(int n) {
		this->n = n;
		locked.assign(n, vector<bool>(n, false));
		v.assign(n, vector<bool>(n, false));
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				char c; cin>>c;
				if(c == '#') locked[i][j] = true;
				else v[i][j] = (c == '1' ? true : false);
			}
		}
		pot.assign(65, 1);
		for(int i = 1; i<=64; i++) pot[i] = pot[i-1]<<1;
		mem.clear();
	}
	ull next(){ // combinei o hash com o hash aqui
		ull hash = 0;
		vector<vector<bool>> new_v = v;
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				int c = 0;
				for(int vi = 0; vi<8; vi++){
					int ni = i+di[vi];
					int nj = j+dj[vi];
					if(ni >= 0 && ni < n && nj >= 0 && nj < n && !locked[ni][nj]) c^=v[ni][nj];
				}
				if(!locked[i][j] && c){
					new_v[i][j] = !v[i][j];
				}
				if(new_v[i][j]) hash += pot[i*n+j];
			}
		}
		v = new_v;
		return hash;
	}

	ull hash(){
		ull res = 0;
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				if(v[i][j])	res += pot[i*n+j];
			}
		}
		return res;
	}

	void printa(){
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				if(locked[i][j]) cout<<'#';
				else cout<<v[i][j];
			} cout<<endl;
		}
		// cout<<it<<endl;
	}


	void simulate(int k){
		mem[this->hash()] = k;

		while(k > 0){
			ull hash = this->next();
			if(mem.find(hash) != mem.end()){
				k %= (mem[hash]-k);
				break;
			} else {
				mem[hash] = k;
			}
			k--;
		}
		while(k > 0) {
			this->next();
			k--;
		}
	}
};


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k; cin>>n>>k;
	game_matrix *m = new game_matrix(n);
	m->simulate(k);
	m->printa();
}