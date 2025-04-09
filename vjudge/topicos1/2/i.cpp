#include <bits/stdc++.h>
#define int long long
#define md 1000000007
using namespace std;

signed main(){
	string s; cin>>s;
	int b; cin>>b;
	vector<int> m(26, 0);
	vector<int> v1(s.size(), 0);
	vector<int> v2(s.size(), 0);
	// vou ler a string de trás para frente e armazenar em v a quantidade de
	// caracteres menores que s[i] lidos até então (que estarão em m). Complexidade 26*10^5
	for(int i = s.size()-1; i>=0; --i){
		int e = s[i]-'a';
		int sum = 0;
		for(int k = e-1; k>=0; --k){
			sum  = (sum+m[k])%md;
		}
		v1[i] = sum;
		m[e]++;
	}
	m.assign(26, 0);
	for(int i = 0; i<s.size(); ++i){
		int e = s[i]-'a';
		int sum = 0;
		for(int k = e-1; k>=0; --k){
			sum  = (sum+m[k])%md;
		}
		v2[i] = sum;
		m[e]++;
	}
	// se b = 4, vou ter uma estrutura do tipo s + s + s + s, cada v[i] do ultimo s soma-se uma
	// vez, do penultimo soma-se duas, do ante penultimo 3 e etc... Assim, para cada v[i], soma-se
	// (1+2+3...b) * v[i], ou seja, pa(1, b) * v[i]. Lembrar do mod.

	// edit*, precisa considerar também um v2 que vai ser lido do inicio ao fim, e soma-se
	// pa(1, b-1)*v2[i].

	b%=md;
	int res = 0;
	int pa1 = (((1+b)*b)/2)%md;
	int pa2 = (((b-1)*b)/2)%md;
	for(int i = 0; i<s.size(); i++){
		res = (res+((v1[i]*pa1)%md))%md;
		res = (res+((v2[i]*pa2)%md))%md;
	}
	cout<<res<<endl;
	
}