#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b; cin>>a>>b;
	queue<pair<int, int>> q; q.push({a, 0});
	
	vector<bool> visitado(10005, false);
	while(!q.empty()){
		auto p = q.front(); q.pop();
		int e = p.first, f = p.second;
		if(e == b) {
			cout<<f<<endl; break;
		}
		if(e > 0 && !visitado[e-1]){
			visitado[e-1] = true;
			q.push({e-1, f+1});
		}
		if(e < 5002 && !visitado[2*e]){
			visitado[2*e] = true;
			q.push({2*e, f+1});
		}
	}
}