#include <bits/stdc++.h>

using namespace std;
int main(){
	string s; cin>>s;
	int maior = 0;
	int x = 0;
	int id = 0;
	for(int i = 0; i<s.size(); i++){
		if(s[i]=='+') x++;
		else x--;
		if(x>maior){
			maior = x;
			id = i;
			}
	}
	cout<<id+1<<endl;
}