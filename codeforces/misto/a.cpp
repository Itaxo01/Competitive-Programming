#include <bits/stdc++.h>


using namespace std;

int main(){
	int n; cin>>n;
	string abc = "aeiou";
	while(n--){
		int a; cin>>a;
		int repeat = a/5;
		a%=5;
		string s = "";
		for(i = 0; i<5; i++){
			if(a>0){
				s+=(abc[i]);
				a--;
			}
			for(int j = 0; j<repeat; j++){
				s+=(abc[i]);
			}
		}
		cout<<s<<endl;
	}
}