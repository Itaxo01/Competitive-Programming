#include <bits/stdc++.h>
using namespace std;


int main(){
	
	int n, m; cin>>n>>m;
	int N = 1 << n;
	vector<int> res(N);
	for(int i = 0; i<N; i++) res[i] = i; // matriz identidade reduzida
	
	for(int E = 0; E<m; E++){
		vector<int> p1(N);
		int op; cin>>op;
		int c1, c2, t;
		if(op == 1){
			cin>>c1>>t;
			c2 = c1;
		} else {
			cin>>c1>>c2>>t;
		}
		for(int i = 0; i<N; i++){
			// só vai existir um cara ligado, portanto se i & (1<<c1) && i & (1<<c2), deve haver um j
			// tal que i ^ (1 << t) == j.
			if((i & (1 << c1)) && (i & (1 << c2))){ 
				p1[i] = (i ^ (1<<t));
			} else {
				p1[i] = i;
			}
		}

		for(int i = 0; i<N; i++){
			res[i] = p1[res[i]];
		}
	}

	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			if(res[i] == j) cout<<1;
			else cout<<0;
		} cout<<endl;
	}
}