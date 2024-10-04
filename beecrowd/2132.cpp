#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(int &counter, string s, bool caminho, int atual, int pos){
	if(pos == s.size()){
		if(caminho) counter+=atual;
		return;
	}
	if(s[pos] == 'a'){
		solve(counter, s, caminho, atual+atual*caminho, pos+1);
	}else if(s[pos] == 'b'){
		if(!caminho){
			solve(counter, s, caminho, atual+atual*caminho, pos+1);
			solve(counter, s, !caminho, atual+atual*caminho, pos+1);
		}else{
			solve(counter, s, caminho, atual+atual*caminho, pos+1);
		}
	}
}

signed main(){
	string s;
	int c = 1;
	while(cin>>s){
		int counter = 0;
		solve(counter, s, false, 1, 0);
		printf("Palavra %lld\n", c++);
		printf("%lld\n", counter);
		printf("\n");
	}
}