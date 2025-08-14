#include <bits/stdc++.h>
#define ll long long
#define all(v) v.begin(), v.end()
using namespace std;

int main(){
	string s; cin>>s;
	int k; cin>>k;
	int n = s.size();

	// cada posição vai pertencer a um conjunto de letras alcançáveis. Só preciso ordenar esses conjuntos. 
	vector<vector<char>> v(k);
	for(int i = 0; i<n; i++){
		v[i%k].push_back(s[i]);
	}
	for(auto &vz: v){
		sort(all(vz));
	}
	int i = n;
	int it = 0;
	while(i--){
		for(int j = 0; j<k; j++){
			if(it < v[j].size()){
				cout<<v[j][it];
			} else {
				cout<<endl;
				return 0;
			}
		}
		it++;
	}

}