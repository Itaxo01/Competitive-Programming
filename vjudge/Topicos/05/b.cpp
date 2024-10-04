#include <bits/stdc++.h>

using namespace std;

int main(){
	while(true){
		int a, b, c; cin>>a>>b>>c;
		if(!a && !b && !c) break;
		int total = 0;
		int arr1[a];
		int arr2[a];
		
		for(int i = 0; i<a; i++){
			cin>>arr1[i];
		}
		for(int i = 0; i<a; i++){
			cin>>arr2[i];
		}
		sort(arr1, arr1+a);
		sort(arr2, arr2+a, greater<int>());
		for(int i = 0 ; i<a; i++){
			int d = arr1[i]+arr2[i];
			if(d>b){
				total+=(d-b);
			}
		}
		cout<<total*c<<endl;
	}
}