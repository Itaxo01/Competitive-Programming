#include <bits/stdc++.h>
using namespace std;

bool all_zero(vector<int> &v){
	for(int i = 0; i<v.size(); i++){
		if(v[i]) return false;
	} return true;
}

bool test(vector<int> &v, int k){
	bool c = true;
	for(int i = 0; i<v.size(); i++){
		if(v[i] == k) c = false;
		else if(c) {
			if(i > 0 && v[i] <= v[i-1]) return false;
		} else {
			if(i > 0 && v[i] >= v[i-1]) return false;
		}
	}
	return true;
}

void printa(vector<int> &v){
	for(int i = 0; i<v.size(); i++){
			if(i) cout<<" ";
			cout<<v[i];
		} cout<<endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	int n; cin>>n;
	vector<int> v(n);
	vector<pair<int, int>> dist1(n), dist2(n);
	for(int i = 0; i<n; i++){
		cin>>v[i];
	}
	if(all_zero(v)){
		for(int i = 1; i<=n; i++){
			if(i > 1) cout<<" ";
			cout<<i;
		} cout<<endl;
		return 0;
	}
	int p = n-1, last_value = -1;
	for(int i = n-1; i>=0; i--){
		if(v[i]){
			last_value = v[i];
			p = i;
		} else {
			dist1[i] = {last_value, p-i};
		}
	}
	
	p = 0, last_value = -1;
	for(int i = 0; i<n; i++){
		if(v[i]){
			last_value = v[i];
			p = i;
		} else {
			dist2[i] = {last_value, i-p};
		}
	}
	
	int l = 0, r = n-1;
	int next = 1;
	while(l < r){
		if(v[l] == next) {
			next++; l++;
		} else if (v[r] == next){
			next++; r--;
		} else if(v[l] && v[r]) {
			l++; r--;
		} else if(v[l]) {
			v[r] = next++; r--;
		} else if(v[r]){
			v[l] = next++; l++;
		}
		// até aqui é apenas preencher
		else { // Se não, há zero nas duas pontas
			// O critério de desempate será definido pelo dist1 e dist2
			// na primeira posição, há o valor do próximo número para aquela posição
			int v1 = dist1[l].first, v2 = dist2[r].first;
			if(v1 == v2){
				if(dist1[l].second < dist2[r].second){
					v[l] = next++;
					l++;
				} else {
					v[r] = next++;
					r--;
				}
			} else if(v1 >= 0 && v1 < v2){
				v[l] = next++;
				l++;
			} else {
				v[r] = next++;
				r--;
			}
		}
		if(l == r && v[l] == 0) v[l] = next;
	} 
	if(test(v, n)){
		printa(v);
	} else cout<<"*"<<endl;
}