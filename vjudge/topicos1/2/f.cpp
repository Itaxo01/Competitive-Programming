#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int n;
	while(cin>>n){
		for(int i = n-2; i>0; i--){
			int aux = n-i;
			if(aux % i == 0) cout<<aux/i<<" ";
		} cout<<endl;
	}
}