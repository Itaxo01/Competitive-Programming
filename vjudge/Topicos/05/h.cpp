#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	int c = 1;
	while(n--){
		int a, b; cin>>a>>b;
		vector<pair<int, char>> v(a);
		for(int i = 0; i<a; i++){
			char s1; int s2;
			cin>>s1>>s2;
			v[i] = {-s2, s1};
		}
		v.push_back({0, 'B'});
		v.push_back({b, 'B'});
		sort(v.begin(), v.end());
		int menor = 0;
		int atual = 0;
		bool anterior = false;
		for(int i = 1; i<v.size(); i++){
			int dif = v[i].first - atual;
			atual = v[i].first;
			if(v[i].second == 'S'){
				if(anterior){
					anterior = false;
					continue;
				}
				v.erase(v.begin()+i);
				i--;
				if(dif>menor) menor = dif;
				anterior = true;
			} else{
				anterior = false;
				if(dif>menor) menor = dif;
			}
		}
		atual = b;
		for(int i = v.size()-1; i>=0; i--){
			int dif = atual-v[i].first;
			if(dif>menor) menor = dif;
			atual = v[i].first;
		}
		printf("Case %d: ", c++);
		cout<<menor<<endl;
	}
}