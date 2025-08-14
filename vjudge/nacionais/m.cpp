#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	vector<int> v(n);
	for(int &e: v) cin>>e;

	int c = 0;
	for(int i = n-1; i>=1; i--){
		if(v[i-1] >= v[i]) c++;
	}
	cout<<n-c<<endl;
}