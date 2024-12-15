#include <bits/stdc++.h>
using namespace std;


void work(){
	string s; cin>>s;
	int two = 0, three = 0;
	int sum = 0;
	for(char c: s){
		sum += c-'0';
		if(c-'0' == 2) two++;
		if(c-'0' == 3) three++;
	}
	if(sum % 9 != 0){
		for(int k = 0; k<=min(three, 3); k++){
			for(int i = 0; i<=min(two, 9); i++){
				if((sum + 2*i + 6*k) % 9 == 0){
					cout<<"YES"<<endl;
					return;
				}
			}
		}
		cout<<"NO"<<endl;
	} else cout<<"YES"<<endl;
}

int main(){
	int tt; cin>>tt;
	while(tt--) work();
}