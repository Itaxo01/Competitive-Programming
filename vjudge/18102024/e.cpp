#include <bits/stdc++.h>

using namespace std;


int main(){
	int n; cin>>n;
	int n0 = pow(n, 2); 
	if(n==0){ 
		cout<<1<<endl;
		return 0;
	}
	int sum = 6;
	for(int x = 1; x<=n; x++){
		int n1 = ceil(sqrt(n0 - pow(x, 2)));
		for(int y = 1; y<=n1; y++){
			int n2 = ceil(sqrt(n0 - pow(x, 2) - pow(y, 2)));
			for(int z = 1; z<=n2; z++){
				if(pow(x, 2) + pow(y, 2) + pow(z, 2) == pow(n, 2)){
					sum+=8;
				}
			}
		}
	}
	for(int x = 1; x<=n; x++){
		int n1 = ceil(sqrt(pow(n, 2) - pow(x, 2)));
		for(int y = 1; y<=n1; y++){
			if(pow(x, 2) + pow(y, 2) == pow(n, 2)){
				sum+=12;
			}
		}
	}

	cout<<sum<<endl;

}