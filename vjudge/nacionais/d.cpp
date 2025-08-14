#include <bits/stdc++.h>
using namespace std;


pair<string, string> parse(string &s){
	int n = s.size();
	int p = -1;
	for(int i = n-1; i>=0; i--){
		if(s[i] == '@') { // pega a posição do @
			p = i;
			break;
		}
	}
	// o que estiver depois do @ será o dominio
	string dominio = s.substr(p+1);
	
	int k = p;
	for(int i = 0; i<p; i++){
		if(s[i] == '+') {
			k = i;
			break;
		}
	}
	string nome = "";
	for(int i = 0; i<k; i++){
		if(s[i] != '.') nome.push_back(s[i]);
	}

	return make_pair(nome, dominio);
}

int main(){
	set<pair<string, string>> mem;
	
	int n; cin>>n;

	for(int i = 0; i<n; i++){
		string s; cin>>s;
		pair<string, string> p = parse(s);
		mem.insert(p);
	}

	cout<<mem.size()<<endl;
}