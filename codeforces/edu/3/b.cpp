#include <bits/stdc++.h>
#define int long long
using namespace std;


int c(int a, int b){
	int sum = 1;
	int j = a-b;
	for(int i = a; i > b; i--){
		sum *= i;
		while(j > 0 && sum % j == 0){
			sum /= j; j--;
		}
	}

	return sum;
}

signed main(){
	int a, b; cin>>a>>b;
	vector<int> v(b, 0);
	for(int i = 0; i<a; i++){
		int c; cin>>c;
		v[c-1]++;
	}
	// n! / k! (n - k)!
	int total = c(a, 2);
	for(int i = 0; i<b; i++){
		if(v[i] > 1) total -= c(v[i], 2);
	}
	cout<<total<<endl;

}