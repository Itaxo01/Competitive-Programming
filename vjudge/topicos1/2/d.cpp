#include <bits/stdc++.h>
#define u_m_si unordered_map<string, int>
#define u_m_ci unordered_map<char, int>
using namespace std;


void build(string &s, string &t, u_m_si &m, u_m_ci &table){
	string aux = ".....";

	for(int i = 0; i<5; i++){
		if(s[i] == t[i]) aux[i] = '*';
		else if(table.find(t[i]) != table.end()) aux[i] = '!';
		else aux[i] = 'X';
	}
	m[aux]++;
}

int main(){
	// a primeira string é a secreta, importante
	int a; cin>>a;
	string secret; cin>>secret;
	u_m_si m;
	u_m_ci table;
	for(auto e: secret) table[e]++;
	build(secret, secret, m, table);

	for(int i = 1; i<a; i++){
		string s; cin>>s;
		build(secret, s, m, table);
	}
	int b; cin>>b;
	for(int i = 0; i<b; i++){
		string s; cin>>s;
		cout<<m[s]<<endl;
	}
}