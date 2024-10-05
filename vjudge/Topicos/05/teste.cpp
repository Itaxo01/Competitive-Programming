#include <bits/stdc++.h>

using namespace std;

int remove(int a){
	int acc = 0;
	for(char e: to_string(a)){
		acc+=e-'0';
	}
	return acc;
}

int main(){
	int n = 1e9;
	int m = 1e6;
	int k = m;
	int counter = 0;
	while(n-m>0 && k>0){
		k-=remove(k);
		n-=m;
		counter++;
	}
	cout<<n<<" "<<k<<" "<<counter<<endl;
}