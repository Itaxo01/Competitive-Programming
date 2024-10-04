#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b; cin>>a>>b;
	vector<int> funcionarios_t(a);
	vector<int> clientes_t(b);
	for(int i = 0; i<a; i++){
		cin>>funcionarios_t[i];
	}
	for(int i = 0; i<b; i++){
		cin>>clientes_t[i];
	}
	int t = 0;
	multiset<pair<int, int>> caixas;
	int maior = 0;
	for(int e:clientes_t){
		if(caixas.size()<a){
			caixas.insert({e*funcionarios_t[t],t});
			if(maior<(e*funcionarios_t[t])) maior = e*funcionarios_t[t];
			t++;
		}
		else{
    		auto it = caixas.begin();
    		auto ti = *it;
			caixas.erase(ti);
    		ti = {ti.first+e*funcionarios_t[ti.second], ti.second};
			caixas.insert(ti);
    		if(ti.first>maior) maior = ti.first;
		}
	}
	cout<<maior<<endl;
}