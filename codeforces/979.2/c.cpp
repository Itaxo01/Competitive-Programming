#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	while(n--){
		int a; cin>>a;
		bool res = false;
		char anterior = 'a';
		for(int i = 0; i<a; i++){
			char t; cin>>t;
			if(t == '1' && t == anterior) res = true;
			if(i == 0 || i == a-1){
				if(t == '1') res = true;
			}
			anterior = t;
		}
		

		if(res) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}