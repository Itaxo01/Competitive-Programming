#include <bits/stdc++.h>
#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int MEX(vector<vector<int>> &v, int pos_i, int pos_j, int max_i, int max_j, 
	map<vector<int>, int> &mem){
	if(pos_i >= max_i || pos_j >= max_j) return 0;
	vector<int> aux = {pos_i, pos_j, max_i, max_j};

	if(mem.find(aux) != mem.end()){
		return mem[aux];
	}
	vector<int> pos(v.size()*v.size()+1, 0);
	for(int i = pos_i; i<max_i; i++){
		for(int j = pos_j; j<max_j; j++){
			pos[v[i][j]]++;
		}
	}
	int res = 0;
	for(int i = 0; i<pos.size(); i++){
		if(pos[i] == 0) {
			res = i;
			break;
		} 
	}
	mem[aux] = res +
		MEX(v, pos_i + 1, pos_j, max_i, max_j, mem) +
		MEX(v, pos_i, pos_j + 1, max_i, max_j, mem) +
		MEX(v, pos_i, pos_j, max_i - 1, max_j, mem) +
		MEX(v, pos_i, pos_j, max_i, max_j - 1, mem);
	return mem[aux];
}

void work(){
	int n; cin>>n;
	vector<int> v(n*n);
	for(int i = 0; i<n*n; i++) v[i] = i;
	int maior = 0;
	vector<vector<int>> v_maior;

	do {
		vector<vector<int>> v_aux(n, vector<int>(n));
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				v_aux[i][j] = v[i*n+j];
			}
		}
		map<vector<int>, int> mem;
		int m = MEX(v_aux, 0, 0, n, n, mem);
		if(m > maior){
			maior = m;
			v_maior = v_aux;
		}
	} while(next_permutation(v.begin(), v.end()));
	cout<<maior<<endl;

	do {
		vector<vector<int>> v_aux(n, vector<int>(n));
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				v_aux[i][j] = v[i*n+j];
			}
		}
		map<vector<int>, int> mem;
		int m = MEX(v_aux, 0, 0, n, n, mem);
		if(m == maior){
			for(int i = 0; i<n; i++){
				for(int j = 0; j<n; j++){
					if(j) cout<<" ";
					cout<<v_aux[i][j];
				} cout<<endl;
			} cout<<endl;
		}
	} while(next_permutation(v.begin(), v.end()));
}

signed main(){
	fastio
	int tt; cin>>tt;
	while(tt--){
		work();
	}
}