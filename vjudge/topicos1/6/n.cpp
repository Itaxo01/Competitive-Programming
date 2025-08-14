#include <bits/stdc++.h>
using namespace std;

void f(int &a, int &b, string &s){
	int i = 0; while(s[i] != '.') i++;
	a += stoi(s.substr(1, i-1));
	b += stoi(s.substr(i+1, s.size()-i));
	a += b/100;
	b %= 100;
}

int main(){
	int n; cin>>n;
	string s; cin>>s;
	int a = 0, b = 0;
	f(a, b, s);
	int ct = 0;
	for(int i = 1; i<=n; i++){
		cin>>s;
		f(a, b, s);
		if(b != 0) ct++;
		// cout<<a<<" "<<b<<endl;
	}
	cout<<ct<<endl;
}