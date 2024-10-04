#include <bits/stdc++.h>
 
using namespace std;
bitset<50001> visitados;

int dfs_(vector<vector<int>> &v){
	int groups = 0;
	int counter = 0;
	queue<int> q;
	while(counter<v.size()){
		if(!visitados.test(counter)){
			q.push(counter);
			groups++;
			visitados.set(counter);
		}
		while(!q.empty()){
			int temp = q.front();
			q.pop();
			for(int e: v[temp]){
				if(!visitados.test(e)){
					visitados.set(e);
					q.push(e);
				}
			}
		}
		counter++;
	}
	return groups;
}

int main() {
    int a, b; cin>>a>>b;
	visitados.reset();
    vector<vector<int>> v(a);
    for(int i = 0 ; i<b; i++){
        int c, d; cin>>c>>d;
        v[c-1].push_back(d-1);
		v[d-1].push_back(c-1);
    }
    cout<<dfs_(v)<<endl;
    
    return 0;
}