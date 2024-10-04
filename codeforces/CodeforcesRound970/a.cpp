#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	for(int i = 0; i<n; i++){
		int a, b; cin>>a>>b;
		if(b%2==0){
			if(a%2==0) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		else{
			if(a%2==0 and a>=2) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}

	}
}