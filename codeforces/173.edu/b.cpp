#include <bits/stdc++.h>
using namespace std;


void work(){
	int n, d; cin>>n>>d;
	cout<<'1';
	if(n >= 3 || (d == 3 || d == 6 || d == 9)) cout<<" 3";
	if(d == 0 || d == 5) cout<<" 5";
	if(n >= 3 || (d == 7)) cout<<" 7";
	if(n >= 6 || d == 9 || ((d == 3 || d == 6) && n>=3)) cout<<" 9";
	cout<<endl;
}

int main(){
	int tt; cin>>tt;
	while(tt--){
		work();
	}
}