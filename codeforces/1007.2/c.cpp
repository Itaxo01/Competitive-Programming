#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>> 
using namespace std;


void work(){
	int a, b, c; cin>>a>>b>>c;
	vector<vector<int>> v(a);
	
	for(int i = 0; i<a-1; i++){
		int u, p; cin>>u>>p;
		u--; p--;
		v[u].push_back(p);
		v[p].push_back(u);
	}
	vector<vector<int>> distances(a);
	// The idea is to create a tree where the end point is the root. From there
	// I just eliminate the leaves every turn and hope for the best.
	int maior = 0;
	if(a > 1){

		vector<bool> visitado(a, false);
		visitado[c-1] = true;
		queue<ii> s; s.push({c-1, 0});
		while(!s.empty()){
			auto q = s.front(); s.pop();
			distances[q.second].push_back(q.first);
			for(int e: v[q.first]) {
				if(!visitado[e]) {
					visitado[e] = true;
					s.push({e, q.second+1});
					maior = max(maior, q.second+1);
				}
			}
		}
		bool first = true;
		for(int i = maior; i>=0; i--){
			for(int e: distances[i]){
				if(!first) cout<<" ";
				first = false;
				cout<<e+1;
			}
		}
		cout<<endl;
	} else cout<<1<<endl;
}


signed main(){
	int tt; cin>>tt;
	while(tt--)
		work();
	return 0;
}