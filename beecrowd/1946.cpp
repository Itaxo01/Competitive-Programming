#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n; 
	while(cin>>n){int div = 0;
	long long total = 1;
	n--;
	long long p2 = 1<<n;
	do{
		n--;
		div++;
		total = (total*n)/div;
	}while(n>div);
	total*=2;
	printf("%.2f\n", (100*total)/(double)p2);
	}
}