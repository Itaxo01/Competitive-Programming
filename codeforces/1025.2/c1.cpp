#include <bits/stdc++.h>
#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

bool add(int y){
	cout<<"add "<<y<<endl;
	cout.flush();
	int a; cin>>a;
	return a == 1;
}

bool div(int y){
	cout<<"div "<<y<<endl;
	cout.flush();
	int a; cin>>a;
	return a == 1;
}

bool mul(int y){
	cout<<"mul "<<y<<endl;
	cout.flush();
	int a; cin>>a;
	return a == 1;
}

bool digit(){
	cout<<"digit"<<endl;
	cout.flush();
	int a; cin>>a;
	return a == 1;
}
bool ans(){
	cout<<"!"<<endl;
	cout.flush();
	int a; cin>>a;
	return a == 1;
}

void work(){
	int n; cin>>n; // [1.. 1000000000]
	if(mul(1e13)){ // [1e18 .. 99999e13]

	} else { // [100000.. 1000000000]
		
	}
	add(n-1);
	ans();
}

signed main(){
	fastio
	int tt; cin>>tt;
	while(tt--){
		work();
	}
}