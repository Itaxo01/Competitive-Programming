#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	while(n--){
		int a, b; cin>>a>>b;
		char c;
		if(a>b) c = '>'; else if(a<b) c = '<'; else c = '=';
		cout<<c<<endl;
	}
}