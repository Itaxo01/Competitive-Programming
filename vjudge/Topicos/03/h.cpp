#include <bits/stdc++.h>

using namespace std;

void solve(vector<pair<char, string>> &letras, set<string> &mem, pair<string, string> s, string &code, vector<string> &respostas){
	if(respostas.size()==100) return;
	if(s.first.size()>code.size()) return;
	if(s.first.size()==code.size())
		if(s.first == code){
			respostas.push_back(s.second);
			return;
		}
	
	mem.insert(s.second);
	for(auto e:letras){
		string stemp1 = s.first+e.second;
		string stemp2 = s.first+'0'+e.second;
		
		s.second = s.second+e.first;
		if(mem.find(s.second)==mem.end()){
			solve(letras, mem, {stemp1, s.second}, code, respostas);
			solve(letras, mem, {stemp2, s.second}, code, respostas);
		}
		s.second.pop_back();
		
	}
	

}


int main(){
	bool first = true;
	int c = 1;
	while(true){
		int n; cin>>n;
		if(!n) break;
		if(!first) cout<<endl;
		printf("Case #%d\n", c++);
		vector<pair<char, string>> letras;
		for(int i = 0; i<n; i++){
			char a; string b; cin>>a>>b;
			letras.push_back({a, b});
		}
		string code; cin>>code;
		vector<string> respostas;
		set<string> mem;
		
		solve(letras, mem, {"", ""}, code, respostas);
		for(string e: respostas){
			cout<<e<<endl;
		}
		first = false;
	}
}