#include <bits/stdc++.h>

using namespace std;
int n;
pair<int, int> esquerda;
pair<int, int> direita;

bool checkValid(pair<int, int> &a, pair<int, int> t){
	if(t.first==a.second){
		return true;
	}if(t.first==a.first){
		swap(a.second, a.first);
		return true;
	}
	return false;
}

void solve(vector<pair<int, int>> &pecas, vector<bool> usadas, stack<pair<int, int>> resultado, bool &answ){
	
	if(resultado.size()==n+1){
		if(checkValid(resultado.top(), direita)){
			answ = true;
			resultado.push(direita);
			return;
		}
	}
	for(int i = 0; i<pecas.size(); i++){
		if(!usadas[i]){
			if(checkValid(pecas[i], resultado.top())){
				usadas[i] = 1;
				resultado.push(pecas[i]);
				solve(pecas, usadas, resultado, answ);
				usadas[i] = 0;
				resultado.pop();
			}
		}
	}
}

int main(){
	while(true){
		cin>>n;
		if(n==0) break;
		int m; cin>>m;
		cin>>esquerda.first>>esquerda.second;
		cin>>direita.first>>direita.second;
		vector<pair<int,int>> pecas;
		for(int i = 0; i<m; i++){
			int a, b; cin>>a>>b;
			pecas.push_back({a, b});
		}
		stack<pair<int, int>> resultado;
		bool answ = false;
		vector<bool> usadas(m, false);
		resultado.push(esquerda);
		solve(pecas, usadas, resultado, answ);
		resultado.pop();
		swap(esquerda.first, esquerda.second);
		resultado.push(esquerda);
		solve(pecas, usadas, resultado, answ);
		resultado.pop();

		if(answ) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}