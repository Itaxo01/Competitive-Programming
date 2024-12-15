#include <bits/stdc++.h>
using namespace std;

string palavra = "";
int maior_count = 0;

bool stringcmp(string &a, string &b){
	for(int i = 0; i<min(a.size(), b.size()); i++){
		if(a[i] == b[i]) continue;
		return a[i] < b[i];
	}
	return a.size() < b.size();
}

class trie{
	public:
		trie *filhos[26];
		char letra;
		int count;
		trie(char c = ' '){
			count = 0;
			letra = c;
			for(int i = 0; i<26; i++) filhos[i] = nullptr;
		}
		void insert(string e, int pos = 0) {
			trie *atual = this;
			for(int i = pos; i<e.size(); i++){
				if(e[i] != '*'){
					if(atual -> filhos[e[i] - 'a'] == nullptr)
						atual -> filhos[e[i] - 'a'] = new trie(e[i]);
					atual = atual->filhos[e[i] - 'a'];
				} else {
					for(int j = 0; j<26; j++){
						e[i] = char(j+'a');
						atual->insert(e, i);
					}
					return;
				}
			}
			atual -> count++;
			if(atual->count > maior_count){
				maior_count = atual->count;
				palavra = e;
			} else if(atual->count == maior_count){
				if(stringcmp(e, palavra)) palavra = e;
			}
		}

};

int main(){
	int a, b; cin>>a>>b;
	trie *t = new trie();
	for(int i = 0; i<a; i++){
		string s; cin>>s;
		t->insert(s);
	}
	cout<<palavra<<" "<<maior_count<<endl;
}