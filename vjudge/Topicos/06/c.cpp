#include <bits/stdc++.h>
#define int long long
using namespace std;

int a, b, c;

bool check(int bm){
	int anterior = bm & (1<<(a-1));
	int grupos = 1;
	int tamanho = 1;
	for(int i = a-2; i>=0; i--){
		if((bm & (1<<i))==anterior){
			tamanho++;
			if(tamanho>c) return false;
		} else {
			grupos++;
			if(grupos>b) return false;
			tamanho = 1;
		}
	}
	if(grupos != b) return false;
	return true;
}

int solve(){
	int p = 1<<a;
	int count = 0;
	for(int i = 0; i<p; i++){
		if(check(i)) count++;
	}
	return count;
}

signed main(){
	while(cin>>a>>b>>c){
		if(b*c>=a)
			cout<<solve()<<endl;
		else cout<<0<<endl;
	}
}