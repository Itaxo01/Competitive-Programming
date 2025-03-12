#include <bits/stdc++.h>
using namespace std;

bool is_leaf(int e, vector<vector<int>> &v, vector<bool> &visited){
	for(int k: v[e]) {
		if(!visited[k]) return false;
	}
	return true;
}

int main(){
	int a, b; cin>>a>>b;
	vector<int> cats(a);
	for(int i = 0; i<a; i++){
		cin>>cats[i];
	}

	vector<vector<int>> v(a);
	for(int i = 0; i<a-1; i++){
		int c, d; cin>>c>>d;
		v[c-1].push_back(d-1);
		v[d-1].push_back(c-1);
	}

	queue<pair<pair<int, int>, int>> q;
	vector<bool> visited(a, false);
	q.push({{0, cats[0]}, cats[0]});
	visited[0] = true;
	int count = 0;
	while(!q.empty()){
		auto p = q.front(); q.pop();
		if(is_leaf(p.first.first, v, visited)) {
			if(p.second <= b) count++;
		} else
			for(int e: v[p.first.first]){
				if(!visited[e]){
					visited[e] = true;
					if(cats[e] == 0) q.push({{e, 0}, p.second});
					else q.push({{e, p.first.second+1}, max(p.second, p.first.second+1)});
				}
			}
	}
	cout<<count<<endl;

}