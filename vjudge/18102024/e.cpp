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
		int x0 = pow(x, 2);
		int n1 = ceil(sqrt(n0 - x0));
		for(int y = 1; y<=n1; y++){
			int y0 = pow(y, 2);
			int n2 = ceil(sqrt(n0 - x0 - y0));
			for(int z = 1; z<=n2; z++){
				if(x0 + y0 + pow(z, 2) == n0){
					sum+=8;
				}
			}
		}
	}
	for(int x = 1; x<=n; x++){
		int x0 = pow(x, 2);
		int n1 = ceil(sqrt(n0 - x0));
		for(int y = 1; y<=n1; y++){
			if(x0 + pow(y, 2) == n0){
				sum+=12;
			}
		}
	}

	cout<<sum<<endl;

}