#include <bits/stdc++.h>

using namespace std;


void work(){
	int a[3];
	cin>>a[0]>>a[1]>>a[2];
	sort(a, a+3);
	if(a[0]==a[1]) cout<<a[2]<<endl;
	else cout<<a[0]<<endl;
}

int main(){
	int n; cin>>n;
	while(n--){
		work();
	}
}