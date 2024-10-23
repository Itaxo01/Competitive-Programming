#include <bits/stdc++.h>


using namespace std;

void work(){
	int a, b, c; cin>>a>>b>>c;
	int anterior = 0, f = c;
	bool res = false;
	for(int i = 0; i<a; i++){
		int l, r; cin>>l>>r;
		int dif = l-anterior;
		if(dif >= b) res = true;
		anterior = r;
	}
	if(c-anterior>=b) res = true;
	if(res) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}

int main(){
	int n; cin>>n;
	while(n--){
		work();
	}
}