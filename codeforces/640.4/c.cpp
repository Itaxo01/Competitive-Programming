#include <bits/stdc++.h>

using namespace std;

void work(){
	int a, b; cin>>a>>b;
	int c = (b-1)/(a-1);
	
	cout<<c+b<<endl;
}

int main(){
	int n; cin>>n;
	while(n--){
		work();
	}
}