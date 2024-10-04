#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; cin>>n;

	for(int k = 0; k<n; k++){
		int a, b; cin>>a>>b;
		int total = 0;
		int pares = (b)/2;
		if(b & 1){
			if(a & 1) total++;
		}
		if(pares & 1) total++;
		if(total & 1) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}