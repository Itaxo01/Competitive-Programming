#include <bits/stdc++.h>

using namespace std;
int main(){
	int n; cin>>n;
	for(int i = 0; i<n; i++){
		int a; cin>>a;
		int arr[a];
		for(int j = 0; j<a; j++){
			cin>>arr[j];
		}
		if(a!=2) cout<<"NO"<<endl;
		else{
			if(abs(arr[1]-arr[0])>1) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
}