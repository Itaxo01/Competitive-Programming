#include <bits/stdc++.h>
#define ll long long

using namespace std;


void work(){
	int a; cin>>a;
	int b[a];
	for(int i = 0; i<a; i++){
		cin>>b[i];
	}
	for(int i = 0; i<a/2; i++){
		int aux = a-i-1;
		if(b[i] == b[i-1] || b[aux] == b[aux+1]) swap(b[i], b[aux]);
	}
	int count = 0;
	for(int i = 1; i<a; i++){
		if(b[i-1]==b[i]) count++;
	}
	cout<<count<<endl;
}

int main(){
	int n; cin>>n;
	while(n--){
		work();
	}
}