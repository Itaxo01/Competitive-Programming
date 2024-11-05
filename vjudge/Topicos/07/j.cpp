#include <bits/stdc++.h>
using namespace std;

int main(){
	while(true){
		int a, b; cin>>a>>b;
		if(!a && !b) break;
		vector<vector<int>> adj(a);
		vector<int> pesos(a, 0);
		for(int i = 0; i<b; i++){
			int c, d; cin>>c>>d;
			adj[c-1].push_back(d-1);
			pesos[d-1]++;
		}
		
		stack<int> ready;
		
		for(int i = 0; i<a; i++){
			if(pesos[i] == 0) 
				ready.push(i);
		}
		
		vector<int> tarefas;

		while(!ready.empty()){
			int t = ready.top();
			ready.pop();
			tarefas.push_back(t);
			for(int v: adj[t]){
				pesos[v]--;
				if(pesos[v] == 0) ready.push(v);
			}
		}

		if(tarefas.size()!=a) cout<<-1;
		else {
			for(int e:tarefas){
				if(e == tarefas[0]) cout<<e+1;
				else cout<<" "<<e+1;
			}
		}
		cout<<endl;
	}
}