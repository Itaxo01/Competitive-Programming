#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b; cin>>a>>b;
	// blocos de -X- ou X-
	int b2 = 3*a - b;
	int b3 = a - b2;
	
	if(b >= 2*a-1 && b <= 3*a){
		if(b3 < 0){
			for(int i = 0; i<b2-2; i++){
				cout<<"X-";
			} cout<<"X"<<endl;
		} else {
			for(int i = 0; i<b3; i++){
				cout<<"-X-";
			} for(int i = 0; i<b2; i++){
				cout<<"X-";
			}
			cout<<endl;
		}
	} else cout<<"*"<<endl;
}