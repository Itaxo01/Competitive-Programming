#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
	int n; cin>>n;
	string s; cin>>s;
	// meio esquisito, mas quando tiver uma estrutura do tipo ()(), sempre soma a quantidade de ( na esquerda vezes ) na direita. Isso para todo par () ().
	// conforme vou varrendo eu salvo os que possuem estrutura () e somo a quantidade de ) com a quantidade de ( salva até então
	
	int t = 1;
	char c = s[0];
	ll res = 0;
	int left = 0;
	for(int i = 1; i<n; i++){
		if(s[i] == c) t++;
		else {
		// ) (
			if(c == ')') {
				res += t*left;
			} else left += t;
			c = s[i];
			t = 1;
		}
	}
	if(c == ')') res += t*left;

	cout<<res<<endl;

}