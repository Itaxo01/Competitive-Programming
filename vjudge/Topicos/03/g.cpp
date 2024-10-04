#include <bits/stdc++.h>


using namespace std;

int main(){
	while(true){
		int t, n; cin>>t>>n;
		if(!t and !n) break;
		int arr[n];
		for(int i = 0; i<n; i++){
			cin>>arr[i];
		}
		int p = 1<<(n+1);
		set<vector<int>, greater<vector<int>>> respostas;
		for(int b = 0; b<p; b++){
			int soma = 0;
			vector<int> s_at;
			for(int j = 0; j<n; j++){
				if(b & (1<<j)){
					soma+=arr[j];
					s_at.push_back(arr[j]);
				}
			}
			if(soma==t){
				respostas.insert(s_at);
			}
		}
		printf("Sums of %d:\n", t);
		if(respostas.empty()) cout<<"NONE"<<endl;
		else{
			for(auto e:respostas){
				bool first = true;
				for(int k:e){
					if(first){
						first = false;
						cout<<k;
					}else cout<<"+"<<k;
				}cout<<endl;
			}
		}
	}
}