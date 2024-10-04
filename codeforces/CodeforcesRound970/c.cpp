#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	for(int i = 0; i<n; i++){
		int a, b; cin>>a>>b;
		int c = a;
		int ic = 1;
		int counter = 0;
		while(c<=b){
			counter++;
			c+=ic;
			ic++;
		}
		cout<<counter<<endl;
	}
}