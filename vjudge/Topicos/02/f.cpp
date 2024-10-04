#include <bits/stdc++.h>
using namespace std;
bitset<1000001> bs;



int main(){
	while(true){
		int a, b; cin>>a>>b;
		if(a==0 and b==0) break;
		bs.reset();	
		bool resposta = true;
		for(int i = 0; i<a; i++){
			int l, r; cin>>l>>r;
			for(int j = l; j<r && resposta; j++){
				if(bs.test(j)){
					resposta = false;
				}
				bs.set(j);
			}
		}
		for(int i = 0; i<b; i++){
			int l, r, f; cin>>l>>r>>f;
			while(l<=1000000){
				for(int j = l; j<min(r, 1000000) && resposta; j++){
					if(bs.test(j)){
						resposta = false;
					}
					bs.set(j);
				}
				l+=f; r+=f;
			}
		}
		if(resposta) cout<<"NO CONFLICT"<<endl;
		else cout <<"CONFLICT"<<endl;
	}
}