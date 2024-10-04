#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	int c = 1;
	while(n--){
		int a; cin>>a;
		string s; cin>>s;
		int ult = 0;
		int counter = 0;
		for(int i = 1; i<a; i++){
			if(s[i-1] == '.'){
				s[i-1] = '#';
				s[i] = '#';
				s[i+1] = '#';
				counter++;
			}
		}
		if(s[a-1]=='.' or s[a-2]=='.') counter++;
		
		printf("Case %d: ", c++);
		cout<<counter<<endl;
	}
}