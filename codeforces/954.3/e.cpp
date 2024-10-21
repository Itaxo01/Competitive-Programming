#include <bits/stdc++.h>
#define int long long
using namespace std;

void work(){
	int a, b; cin>>a>>b;
	map<int, vector<int>> m;

	for(int i = 0; i<a; i++){
		int c; cin>>c;
		m[c%b].push_back(c);
	}
	int impar = 0;
	int soma = 0;
	for(auto it = m.begin(); it!=m.end(); it++){
		vector<int> v = (*it).second;
		sort(v.begin(), v.end());
		if(v.size() & 1){
			impar++;
			if(impar == 2){
				cout<<-1<<endl;
				return;
			} else {
				int a1[v.size()/2];
				int a2[v.size()/2];
				int custo = 0;
				for(int i = 0; i<v.size()-1; i+=2){
					a1[i/2] = v[i+1]-v[i];
				}
				for(int i = 1; i<v.size(); i+=2){
					a2[i/2] = v[i+1]-v[i];
					custo += a2[i/2];
				}
				int menor = custo;
				for(int i = 2; i<v.size(); i+=2){
					custo = custo-a2[(i/2)-1]+a1[(i/2)-1];
					menor = min(custo, menor);
				}
				soma+=menor;
			}
		} else{
			for(int i = 0; i<v.size(); i+=2){
				soma += v[i+1]-v[i];
			}
		}
	}
	cout<<soma/b<<endl;

}

signed main(){
	int n; cin>>n;
	while(n--){
		work();
	}
}