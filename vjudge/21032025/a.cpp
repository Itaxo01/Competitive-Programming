#include <bits/stdc++.h>
using namespace std;

class node{
	public:
		string s;
		int count = 0;
		int maior_abaixo = 0;
		string maior_abaixo_s;
		node *filhos[26];
		node(){}
	private:
};

class trie{
	public:
		node *root;
		trie(){
			root = new node();
		}
		void insert(string &s_){
			node *aux = root;
			for(int i = 0; i<s_.size(); i++){
				char e = s_[i];
				if(aux -> filhos[e-'a'] == nullptr){
					aux -> filhos[e-'a'] = new node();
				}
				aux = aux->filhos[e-'a'];
			}
			aux ->count++;
			aux ->s = s_;
			node *temp = root;
			for(int i = 0; i<s_.size(); i++){
				if(aux ->count > temp ->maior_abaixo){
					temp ->maior_abaixo = aux->count;
					temp ->maior_abaixo_s = s_;
				} else if(aux ->count == temp ->maior_abaixo){
					if(s_ < temp ->maior_abaixo_s){
						temp ->maior_abaixo_s = s_;
					}
				}
				temp = temp->filhos[s_[i]-'a'];
			}
		}
		pair<int, string> find_biggest(string &s){
			node *aux = root;
			int i = 0;
			while(i < s.size() && aux -> filhos[s[i]-'a'] != nullptr){
				aux = aux -> filhos[s[i]-'a'];
				i++;
			}
			if(i < s.size()) return {-1, "-1"};
			if(aux -> count > aux ->maior_abaixo){
				return {aux->count, aux->s};
			}
			if(aux -> count == aux ->maior_abaixo && aux -> s < aux -> maior_abaixo_s){
				return {aux->count, aux->s};
			}
			return {aux->maior_abaixo, aux->maior_abaixo_s};
		}
	private:
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a; cin>>a;
	trie *t = new trie();
	for(int i = 0; i<a; i++){
		string s; cin>>s;
		t->insert(s);
	}
	int b; cin>>b;
	map<string, pair<int, string>> m;
	for(int i = 0; i<b; i++){
		string s; cin>>s;
		if(m.find(s) == m.end()){
			m[s] = t->find_biggest(s);
		}
		if(m[s].first == -1) cout<<"-1\n";
		else cout<<m[s].second<<" "<<m[s].first<<endl;
	}

}