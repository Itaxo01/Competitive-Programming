#include <bits/stdc++.h>

using namespace std;

int main(){
	int a; cin>>a;
	char b; cin>>b;
	if(b=='a'){
		for(int i = 1; i<=a; i++){
			if(i == 1) cout<<i;
			else cout<<" "<<i;
		}cout<<endl;
	}else{
		for(int i = a; i>0; i--){
			if(i == a) cout<<i;
			else cout<<" "<<i;
		}cout<<endl;
	}
}