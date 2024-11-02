#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int n; cin>>n;
	for(int i = 1; i<=floor(sqrt(n)); i++){
		printf("%ld\n", (int)pow(i, 2));
	}
}