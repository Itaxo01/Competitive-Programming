#include <bits/stdc++.h>


using namespace std;
int main(){
	int n; cin>>n;

	for(int i = 0; i<n; i++){
		int a; cin>>a;
		string s; cin>>s;
		
		int maior_im = 0;
		int maior_par = 0;
		int res = 0;

		vector<char, int> direita_par(26, 0);
		vector<char, int> direita_impar(26, 0);
		vector<char, int> esquerda_par(26, 0);
		vector<char, int> esquerda_impar(26, 0);
		

		int maior_p, maior_i;
		for(int i = 0; i<a; i++){
			if(i & 1 ){
				direita_impar[s[i]-'a']++;
				if(direita_impar[s[i]-'a']>maior_i) maior_i = direita_impar[s[i]-'a'];
			}else{
				direita_par[s[i]-'a']++;
				if(direita_par[s[i]-'a']>maior_p) maior_p = direita_par[s[i]-'a'];
			}
		}

		if(s.size()&1){
			char anterior = s[0];
			for(int k = 1; k<s.size(); k++){
				char atual = s[k];
				if((k-1) & 1){
					if(esquerda_impar.find(anterior)!=esquerda_impar.end()){
						esquerda_impar[anterior]++;
					}else esquerda_impar[anterior] = {1};
					direita_par[atual]--;

					if(esquerda_impar[anterior]>maior_i) maior_i = esquerda_impar[anterior];
				}else{
					if(esquerda_par.find(anterior)!=esquerda_par.end()){
						esquerda_par[anterior]++;
					}else esquerda_par[anterior] = {1};
					if(esquerda_par[anterior]>maior_p) maior_p = esquerda_par[anterior];
				}
				



				// char middle = s[k];
				// string prefix = s.substr(0, k);
				// string sufix = s.substr(k+1, s.size()-k);
				anterior = atual;

			}
		}



		map<char, int> p;
		map<char, int> o;
		for(int e = 0; e<s.size(); e++){
			if(e & 1){
				if(o.find(s[e])!=o.end()){
					o[s[e]]++;
				}
				else o.insert({s[e], 1});
				if(maior_im<o[s[e]]) maior_im = o[s[e]];
			}else{
				if(p.find(s[e])!=p.end()){
					p[s[e]]++;
				}
				else p.insert({s[e], 1});
				if(maior_par<p[s[e]]) maior_par = p[s[e]];
			}
		}
		res += s.size()-(maior_im+maior_par);
		cout<<res<<endl;
		
	
	}
}