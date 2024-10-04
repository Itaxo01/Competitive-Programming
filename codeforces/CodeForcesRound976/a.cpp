#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	while(n--){
		int counter = 0;
		long long a, d; cin>>a>>d;
		if(d==1){
			cout<<a<<endl;
			continue;
		}
		while(a){
			long long b = 1;
			while(b*d<=a){
				b*=d;
			}
			counter+=a/b;
			a = a-b*(a/b);

		}
		cout<<counter<<endl;
	}
}