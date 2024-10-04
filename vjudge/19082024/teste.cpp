#include <bits/stdc++.h>

using namespace std;
int main(){
	int n = 1000000;
	cout<<n<<endl;
	for(int i = 1; i<=n; i++){
		int v1 = rand()%(n/2)+1;
		int v2 = rand()%(n/2)+1+n/2;
		cout<<v1<<" "<<v2<<endl;
	}
}