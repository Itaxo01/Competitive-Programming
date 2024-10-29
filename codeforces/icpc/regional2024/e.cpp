#include <bits/stdc++.h>
using namespace std;



int main(){
	int a; cin>>a;
	int menor = INT_MAX;
	int i_, j_;
	for(int i = 0; i<a; i++){
		for(int j = 0 ; j < a ; j++){
			int c; cin>>c;
			if(c<menor){
				menor = c;
				i_ = i;
				j_ = j;
			}
		}
	}
	int i = i_, j = j_;
	if(i == 0 && j == 0) cout<<0<<endl;
	else if(i == 0 && j == a-1) cout<<1<<endl;
	else if(i == a-1 && j == a-1) cout<<2<<endl;
	else cout<<3<<endl;
	
}