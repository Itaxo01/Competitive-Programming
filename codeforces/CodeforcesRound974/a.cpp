#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	while(n--){
		int a; cin>>a;
		int b, c; cin>>b>>c;
		int d = min(b, c);
		if(a%d) cout<<(a/d)+1<<endl;
		else cout<<(a/d)<<endl;

	}
	return 0;
}