#include <bits/stdc++.h>
using namespace std;


int main(){
	int n; cin>>n;
	vector<pair<int, int>> v(n);
	vector<int> w(n);
	for(int i = 0; i<n; i++){
		int a, b; cin>>a>>b;
		v[i] = {b, i};
		w[i] = a;
	}
	int sum = 0;
	vector<int> p;
	sort(v.begin(), v.end());
	for(auto e: v){
		sum += w[e.second];
		if(sum > e.first){
			cout<<"*"<<endl;
			return 0;
		}
		p.push_back(e.second);
	}
	priority_queue<pair<int, int>> menor_pos; // Guarda a menor posição para dar swap e qual sua posição real no vetor
	map<int, int> menor_limite;
	int pos = 0, i = 1;
	int disloc = 0;
	menor_pos.push({v[0].second, 0});
	while(i < n){
		auto e = v[i];
		sum += w[e.second];
		auto it = menor_limite.begin();
		if(sum > it->first){
			auto nxt = menor_pos.top(); menor_pos.pop();
			swap(v[pos], v[2]);
			pos++;
		}
		menor_limite[e.first]++;
		i++;
	}


	for(int i = 0; i<n; i++){
		if(i) cout<<" ";
		cout<<p[i]+1;
	} cout<<endl;
}