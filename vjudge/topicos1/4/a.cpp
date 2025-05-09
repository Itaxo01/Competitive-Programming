#include <bits/stdc++.h>
#define int long long
using namespace std;

//int res = 0;
//bool cmp(string &s1, string &s2){
//	int o1 = order.find(s1[0]);
//	int o2 = order.find(s2[0]);
//	return (o1 < o2) ||
//	    (o1 == o2 && stoi(s1.substr(1)) < stoi(s2.substr(1)));
//}

int LIS(vector<int> &v){
	// Important: s is not the LIS vector, but it's size is.
	vector<int> s; int n = v.size();
	for(int i = 0; i<n; i++){
		auto it = upper_bound(s.begin(), s.end(), v[i]);
		if(it != s.end()) s.erase(it);
		s.insert(it, v[i]);
	}
	return s.size();
}


signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	// é simplesmente n menos a LIS (Longest Increasing Substring)
	// pois a LIS representa a subsequencia ótima que não irá ser modificada
	// e as demais posições serão inseridas em suas posições finais diretamente.
	
	// Para aplicar a LIS tradicional, apenas farei um truque convertendo a string para
	// um valor. O valor de uma string S será (n+1) * pos(s[0]) + s[1:]

	// Edit: Detalhe da questão que passou despercebido, não é falado a ordem dos outros nipes,
	// somente que o ciano vem depois de todos. Assim sendo, precisa se considerar todas as possiveis ordenações
	string base = "SWER"; string aux = base;
	vector<string> bases;
	do {
		bases.push_back(aux + 'C');
		next_permutation(aux.begin(), aux.end());
	} while (aux != base);
	
	int n; cin>>n;
	vector<string> v(n);

	for(int i = 0; i<n; i++){
		cin>>v[i];
	}
	int menor = INT_MAX;
	for(string e: bases){
		vector<int> v1(n);
		for(int i = 0; i<n; i++){
			string s = v[i];
			v1[i] = (n+1)*e.find(s[0]) + stoi(s.substr(1));
		}
		menor = min(menor, n-LIS(v1));
	}
	cout<<menor<<endl;
}