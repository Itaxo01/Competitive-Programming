#include <bits/stdc++.h>

using namespace std;

void solve(pair<string, string> s, vector<pair<string, string>> &vp, string &code, vector<string> &resultados){
	if(resultados.size()==100) return;
	if(s.second.size()==code.size()){
		if(s.second==code){
			resultados.push_back(s.first);
		}
		return;
	}
	if(s.second.size()>code.size()) return;
	string zeros = "";
	for(int i = s.second.size(); i<code.size(); i++){
		if(code[i]!='0') break;
		zeros+="0";
	}
	for(auto e: vp){
		pair<string, string> s1 = {s.first+e.first, s.second+zeros+e.second};

		if(s1.second==code.substr(0, s1.second.size())){
			solve(s1, vp, code, resultados);
		}
	
	}
}


int main(){
	int c = 1;
	while(true){
		int n; cin>>n;
		if(!n) break;
		printf("Case #%d\n", c++);
		vector<pair<string, string>> vp(n);
		for(int i = 0; i<n; i++){
			cin>>vp[i].first>>vp[i].second;
		}
		sort(vp.begin(), vp.end());
		string code; cin>>code;

		vector<string> resultados;
		solve({"", ""}, vp, code, resultados);
		for(auto e:resultados){
			cout<<e<<endl;
		}
		cout<<endl;
	}
}