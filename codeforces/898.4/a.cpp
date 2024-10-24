#include <bits/stdc++.h>

using namespace std;

void work(){
	string a;
	cin>>a;
	int count = 0;
	if(a[0]=='a') count++;
	if(a[1]=='b') count++;
	if(a[2]=='c') count++;
	if(count>=1) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}

int main(){
	int n; cin>>n;
	while(n--){
		work();
	}
}