#include <bits/stdc++.h>
using namespace std;

int bfs(int a, int b, int res, vector<vector<int>> &v){
	if(a == b) return 0;
	vector<bool> visitados(v.size(), false);
	queue<pair<int, int>> q;
	q.push({a, 0});
	while(!q.empty()){
		auto p = q.front();
		if(p.first == b) return p.second;
		q.pop();
		for(auto k: v[p.first]){
			if(!visitados[k]){
				visitados[k] = true;
				q.push({k, p.second+1});
			}
		}
	}
	return -1;
}

int difference(string a, string b){
	if(a.size() != b.size()) return -1;
	int count = 0;
	for(int i = 0; i<a.size(); i++){
		if(a[i] != b[i]) count++;
	}
	return count;
}

int main(){
	int tt; cin>>tt;
	bool first = true;

	while(tt--){
		if(!first) cout<<endl;
		first = false;
		
		string s;
		vector<string> words;
		while(cin>>s){
			if(s[0] == '*') break;
			words.push_back(s);
		}

		map<string, int> m;
		vector<vector<int>> adj(words.size());
		for(auto k: words){
			if(m.find(k) == m.end()) m[k] = m.size();
			for(auto e: m){
				if(e.first == k) continue;
				if(difference(e.first, k) == 1){
					adj[e.second].push_back(m[k]);
					adj[m[k]].push_back(e.second);
				}
			}
		}

		getline(cin, s);
		while(getline(cin, s)){
			if(s.size()==0) break;
			stringstream ss(s);
			string s1, s2;
			ss>>s1>>s2;
			int a = m[s1], b = m[s2];
			cout<<s1<<" "<<s2<<" "<<bfs(a, b, 0, adj)<<endl;
		}
	}
}