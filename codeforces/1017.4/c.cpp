#include <bits/stdc++.h>
#define int long long
using namespace std;

void work(){
	int n; cin>>n;
	vector<vector<int>> v(n, vector<int>(n));
	vector<int> p(2*n);
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cin>>v[i][j];
		}
	}
	vector<bool> visitados(2*n+1, false);
	int pos = 1;
	int i = 0, j = 0;
	bool add_i = true;
	while(i < n && j < n && pos < 2*n){
		p[pos] = v[i][j];
		visitados[p[pos]] = true;
		if(add_i) i++;
		else j++;
		add_i = !add_i;
		pos++;
	}
	for(int i = 1; i<2*n+1; i++){
		if(!visitados[i]) p[0] = i;
	}

	for(int i = 0; i<2*n; i++){
		if(i) cout<<" ";
		cout<<p[i];
	} cout<<endl;

}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt; cin>>tt;
	while(tt--){
		work();
	}
}