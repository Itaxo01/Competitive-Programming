#include <bits/stdc++.h>
using namespace std;
#define no_ans {cout<<"*\n"; return 0;}
#define all(v) v.begin(), v.end()

void printa(vector<vector<int>> &v){
	for(int i = 0; i<v.size(); i++){
		for(int j = 0; j<v.size(); j++){
			if(j) cout<<" ";
			cout<<v[i][j];
		}
		cout<<endl;
	}
}

bool latin_square(vector<vector<int>> &v){
	int n = v.size();
	for(int i = 0; i<n; i++){
		unordered_map<int, int> l, c;
		for(int j = 0; j<n; j++){
			if(l.find(v[i][j]) != l.end()) return false;
			if(c.find(v[j][i]) != c.end()) return false;
			l[v[i][j]]++;
			c[v[j][i]]++;
			if(v[i][j] == 0) return false;
		}
	}
	return true;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, q; cin>>n>>q;
	vector<int> colunas(n), linhas(n);
	for(int i = 0; i<n; i++){
		colunas[i] = i; linhas[i] = i;
	}

	for(int i = 0; i<q; i++){
		char c; cin>>c;
		int l, r; cin>>l>>r;
		if(c == 'R') swap(linhas[l-1], linhas[r-1]);
		else swap(colunas[l-1], colunas[r-1]);
	}

	bool res = true;
	vector<vector<int>> ciclo_l, ciclo_c;

	set<int> dif_ciclo;
	vector<bool> visited(n, false);
	for(int i = 0; i<n; i++){
		if(visited[i]) continue;
		visited[i] = true;
		int count = 1;
		int ni = linhas[i];
		vector<int> c;
		c.push_back(i);
		while(ni != i){
			count++;
			visited[ni] = true;
			c.push_back(ni);
			ni = linhas[ni];
		}
		ciclo_l.push_back(c);
		dif_ciclo.insert(count);
	}
	visited.assign(n, false);
	for(int i = 0; i<n; i++){
		if(visited[i]) continue;
		visited[i] = true;
		int count = 1;
		int ni = colunas[i];
		vector<int> c;
		c.push_back(i);
		while(ni != i){
			count++;
			visited[ni] = true;
			c.push_back(ni);
			ni = colunas[ni];
		}
		ciclo_c.push_back(c);
		dif_ciclo.insert(count);
	}
	if(ciclo_l.size() != ciclo_c.size() || dif_ciclo.size() > 1) no_ans
	
	
	vector<vector<int>> v(n, vector<int>(n));
	int K = ciclo_c.size();
	int S = ciclo_c[0].size();
	for(int bi = 0; bi<K; bi++){
		int color = S*bi;
		for(int bj = 0; bj<K; bj++){
			for(int i = 0; i<S; i++){
				for(int j = 0; j< S; j++){
					int ii = ciclo_l[bi][i];
					int jj = ciclo_c[bj][j];

					v[ii][jj] = ((i - j + S) % S) + 1 + color;
				}
			}
			color = (S+color)%n;
		}
	}
	// cout<<latin_square(v)<<endl;
	printa(v);

}