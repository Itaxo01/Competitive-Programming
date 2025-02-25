#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	for(int i = 0; i<n; i++){
		int m, k; cin>>m>>k;
		vector<int> v(m, 0);
		vector<vector<int>> dependentes(m);
		
		for(int i = 0; i<k; i++){
			int a, b; cin>>a>>b;
			v[a-1]++; dependentes[b-1].push_back(a-1);
		}
		
		vector<int> proximos;
		int count = 0;
		for(int i = 0; i<m; i++){
			if(v[i] == 0) proximos.push_back(i);
		}

		while(!proximos.empty()){
			int p = proximos.back(); proximos.pop_back();
			count++;
			for(int e: dependentes[p]){
				v[e]--; if(v[e] == 0) proximos.push_back(e);
			}
		}

		if(count == m) cout<<"NAO";
		else cout<<"SIM";
		cout<<endl;
	}
}