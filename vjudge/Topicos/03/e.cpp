#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	while(cin>>n>>m){
		vector<int> musicas(m);
		for(int i = 0; i<m; i++){
			cin>>musicas[i];
		}
		int bitmask = 1<<(m+1);
		bool maior_ = false;
		int maior = 0;
		int maior_bs = 0;
		for(int bm = 0; bm<bitmask && !maior_; bm++){
			int soma = 0;
			for(int j = 0; j<m; j++){
				if(bm & (1<<j)){
					soma+=musicas[j];
				}
			}
			if(soma==n){
				maior_ = true;
				maior = soma;
				maior_bs = bm;
			}else if(soma<n){
				if(soma>maior){
					maior = soma;
					maior_bs = bm;
				}
			}
		}
		vector<int> resposta;
		for(int j = 0; j<m; j++){
			if(maior_bs & (1<<j)) resposta.push_back(musicas[j]);
		}
		for(int e:resposta){
			cout<<e<<" ";
		}
		cout<<"sum:"<<maior<<endl;
	}
}