#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	while(n--){
		long long a; cin>>a;
		long long k = a;
		long long counter = ((sqrt(1 + 4 * a)) - 1) / 2;
		long long c1 = floor(counter-0.0000001);

		cout<<k+c1+1<<endl;

	}
}