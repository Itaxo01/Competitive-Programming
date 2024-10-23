#include <bits/stdc++.h>

using namespace std;


void work(){
	for(int i = 0; i<3; i++){
		string s; cin>>s;
		bool a = false, b = false, c = false;
		bool q = false;
		for(char e: s){
			if(e == 'A') a = true;
			if(e == 'B') b = true;
			if(e == 'C') c = true;
			if(e == '?') q = true;
		} 
		if(q){
			if(!a) cout<<"A"<<endl;
			if(!b) cout<<"B"<<endl;
			if(!c) cout<<"C"<<endl;
			
		}
	}
}

int main(){
	int n; cin>>n;
	while(n--){
		work();
	}
}