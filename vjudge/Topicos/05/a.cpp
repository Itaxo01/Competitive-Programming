#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	while(n--){
		int a; cin>>a;
		int arr[a];
		int k = 0, counter = 0;
		if(a>1) counter++;
		for(int i = 0; i<a; i++){
			cin>>arr[i];
		}
		for(int i = 0; i<a-1; i++){
			if(k+arr[i]<arr[i+1]){
				counter++;
				k+=arr[i];
			}
		}

		cout<<counter<<endl;
	}
}