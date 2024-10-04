#include <bits/stdc++.h>

using namespace std;

int main(){
	int n = 1e9+6;
	int c = 1e3;
	cout<<c<<endl;
	for(int i = 1; i<=c; i++){
		cout<<i<<endl;
		bool first = true;
		for(int k = 0; k<i; k++){
			if(first){
				first = false;
				cout<<n;
			}
			else cout<<" "<<n;
		}cout<<endl;
	}
}