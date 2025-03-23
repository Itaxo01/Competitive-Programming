#include <bits/stdc++.h>
using namespace std;

void work(){
	int a; cin>>a;
	unordered_map<int, pair<int, int>> m;
	for(int i = 0; i<2*a; i++){
		int b; cin>>b;
		if(b > 0){
			m[b-1].first = i;
		} else{
			m[abs(b)-1].second = i;
		}
	}
	// Ideia do editorial
	// Será um caminho tranquilo se para duas entradas sua ordem for
	// +a +b -b -a   ou    +a -a +b -b
	// Será critico caso seja  +a +b -a -b
	// Para todos os pares a b, eu verifico a ordem em que os mesmos entram,
	// e caso seja crítico, adiciono uma arresta em um vértice e depois faço
	// a bicoloração para ver se é possível
	vector<vector<int>> v(a);
	for(int i = 0; i<a; i++){
		int b1 = m[i].first, e1 = m[i].second;
		for(int j = 0; j<a; j++){
			int b2 = m[j].first, e2 = m[j].second;
			if(b1 < b2 && b2 < e1 && e1 < e2){
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
	}

	bool res = true;
	vector<bool> visited(a, false);
	vector<bool> colors(a, false);
	for(int i = 0; i<a; i++){
		if(!visited[i]){
			visited[i] = true;
			queue<pair<int, bool>> q; q.push({i, false});
			while(!q.empty()){
				auto p = q.front(); q.pop();
				for(int e: v[p.first]){
					if(!visited[e]){
						visited[e] = true;
						colors[e] = !p.second;
						q.push({e, !p.second});
					} else if(colors[e] != !p.second) {
						res = false;
						goto finnaly;
					}
				}				
			}
		}
	}

	finnaly:
	if(!res) cout<<"*\n";
	else {
		for(auto e: colors){
			if(!e) cout<<'G';
			else cout<<'S';
		} cout<<endl;
	}
}

int main(){
	// int tt; cin>>tt;
	// while(tt--){
		work();
	// }	
}