#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	while(n--){
		int a, b; cin>>a>>b;
		int sizes[b];
		bool resposta = false;
		for(int i = 0; i<b; i++){
			cin>>sizes[i];
		}
		int bitmask = (1<<(b+1));
		for(int bs = 0; bs<bitmask; bs++){
			int total = 0;
			for(int j = 0; j<b; j++){
				if(bs & (1<<j)){
					total+=sizes[j];
				}
			}
			if(total==a){
				resposta = true;
			}
		}
		if(resposta) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}