#include <bits/stdc++.h>
#define ll long long

using namespace std;

void work(){
	int a; cin>>a;
	int x = 0;
	int i = 1;
	int p = 0;
	while(abs(x)<=a){
		if(p){
			x = x+(2*i-1);
		}else{
			x = x-(2*i-1);
		}
		// cout<<p<<" "<<x<<endl;
		p = (p+1)%2;
		i++;
	}
	if(p) cout<<"Sakurako"<<endl;
	else cout<<"Kosuke"<<endl;
}

int main(){
	int n; cin>>n;
	while(n--){
		work();
	}
}