#include <bits/stdc++.h>

using namespace std;

void work(){
	int a; cin>>a;
	int w = 0, h = 0;
	for(int i = 0; i<a; i++){
		int b, c; cin>>b>>c;
		w = max(w, b);
		h = max(h, c);
	}
	cout<<2*(w+h)<<endl;
}

int main(){
	int n; cin>>n;
	while(n--){
		work();
	}
}