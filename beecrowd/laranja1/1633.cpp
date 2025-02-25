#include <bits/stdc++.h>
#define int long long
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b){
	return a.first > b.first || 
		(a.first == b.first && a.second > b.second);
}

signed main(){
	int n; 
	while(cin>>n){
		vector<pair<int, int>> entradas;
		int tempo = 0;
		int prox = 1;
		for(int i = 0; i<n; i++){
			int a, b; cin>>a>>b;
			entradas.push_back({a, b});
		}
		sort(entradas.begin(), entradas.end(), cmp);
		priority_queue<pair<int, int>> proximos;
		while(!entradas.empty()){
			auto p = entradas.back();
			if(p.first <= prox) {
				while(p.first <= prox){
					proximos.push({-p.second, p.first}); 
					entradas.pop_back();
					if(entradas.empty()) break;
					p = entradas.back();
				}
			} else if(proximos.empty()) {
				proximos.push({-p.second, p.first}); 
				entradas.pop_back();
			}
			tempo += max((long long)0, prox - proximos.top().second);
			prox = max(prox, proximos.top().second) - proximos.top().first;
			proximos.pop();
		}
		while(proximos.size() > 1){
			tempo += max((long long)0, prox - proximos.top().second);
			prox -= proximos.top().first;
			proximos.pop();
		}
		if(proximos.size() == 1) tempo += max((long long)0, prox - proximos.top().second);
		cout<<tempo<<endl;
	}
}