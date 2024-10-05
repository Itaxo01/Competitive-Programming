#include <bits/stdc++.h>

using namespace std;

int main(){
	while(true){
		int a, b; cin>>a>>b;
		if(!a && !b) break;	
		deque<pair<int, int>> v(b);
		for(int i = 0; i<b; i++){
			int c, d; cin>>c>>d;
			v[i] = {max(c-d, 0), min(c+d, a)};
		}
		v.push_front({0, 0});
		v.push_back({a, a});
		sort(v.begin(), v.end());
		int anterior = 0;
		int proximo = 0;
		int counter = 0;
		int i = 0;
		bool resposta = true;
		while(i<v.size()-1){
			while(i+1<v.size() && v[i+1].first<=v[anterior].second){
				i++;
				if(v[i].second>=v[proximo].second) proximo = i;
			}
			counter+= proximo-anterior-1;
			i = proximo;
			if(i<v.size()-1 && v[i].second == a){
				counter+= v.size()-i-1;
				break;
			}
			if(i+1 == v.size()) break;
			if(v[anterior] == v[i]){
				resposta = false;
				break;
			}
			anterior = proximo;
		}
		counter-=1;
		if(resposta) cout<<counter<<endl;
		else cout<<"-1"<<endl;
	}
}