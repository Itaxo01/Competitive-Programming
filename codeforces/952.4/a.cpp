#include <bits/stdc++.h>

using namespace std;

void work(){
	string a, b; cin>>a>>b;
	swap(a[0], b[0]);
	cout<<a<<" "<<b<<endl;
}

int main(){
	int n; cin>>n;
	while(n--){
		work();
	}
}