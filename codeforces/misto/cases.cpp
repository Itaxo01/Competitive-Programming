#include <bits/stdc++.h>

using namespace std;

int main(){
	int n = 100;
	cout<<n<<endl;
	for(int i = 0; i<n; i++){
		int a = rand()%20000-10000;
		int b = rand()%20000-10000;
		cout<<a<<" "<<b<<endl;
	}
	cout<<0<<endl;
}