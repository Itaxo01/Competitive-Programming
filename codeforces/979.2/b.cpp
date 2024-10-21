#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	while(n--){
		int a; cin>>a;
		if(a == 1){
			cout<<'0'<<endl;
			continue;
		}
		while(--a) cout<<'0';
		cout<<'1'<<endl;
	}
}