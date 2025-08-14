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

int main(){
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

	vector<set<int>> l_pos(n), c_pos(n);
	for(auto &e: l_pos) for(int i = 1; i<=n; i++) e.insert(i);
	for(auto &e: c_pos) for(int i = 1; i<=n; i++) e.insert(i);

	int k = -1;
	bool res = true;
	vector<vector<int>> v(n, vector<int>(n));

	vector<vector<bool>> visited(n, vector<bool>(n, false));
	for(int i =0 ; i<n; i++){
		for(int j = 0; j<n; j++){
			if(visited[i][j]) continue;
			int count_i = 1, count_j = 1;
			visited[i][j] = true;
			int ni = linhas[i], nj = colunas[j];
			vector<pair<int, int>> pos;
			pos.push_back({i, j});

			while(ni != i && nj != j){
				visited[ni][nj] = true;
				count_i++;
				count_j++;

				pos.push_back({ni, nj});
				ni = linhas[ni];
				nj = colunas[nj];
			}
			if(ni != i || nj != j) no_ans
			if(k == -1) {
				k = count_i;
				if(n % k) no_ans
			} else if(count_i != k) no_ans

			set<int> aux;
			for(int it = 0; it<pos.size(); it++){
				int pos_i = pos[it].first, pos_j = pos[it].second;
				if(it == 0){
					set_intersection(all(l_pos[pos_i]), all(c_pos[pos_j]), inserter(aux, aux.begin()));
				} else {
					set<int> temp;
					set<int> aux2;
					set_intersection(all(l_pos[pos_i]), all(c_pos[pos_j]), inserter(aux2, aux2.begin()));
					set_intersection(all(aux), all(aux2), inserter(temp, temp.begin()));
					aux = temp;
				}
			}
			int val = *aux.begin();
			for(auto &e: pos){
				int ei = e.first, ej = e.second;
				v[ei][ej] = val;
				l_pos[ei].erase(val);
				c_pos[ej].erase(val);
			}
		}
	}

	printa(v);

}