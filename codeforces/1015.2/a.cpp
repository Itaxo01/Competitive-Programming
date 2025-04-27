#include <bits/stdc++.h>
using namespace std;

void work(){
	// para cada i, i-1, max(p[i], p[i-1]) % i = i-1, ou seja, max(p[i], p[i-1]) = k*i-1;
	// (max(p[i], p[i-1]) + 1) % i == 0
	// 1 5 2 3 4
	int n; cin>>n;
	if(!(n & 1)) cout<<-1<<endl;
	else {
		cout<<n;
		for(int i = 1; i<n; i++){
			cout<<" "<<i;
		} cout<<endl;
	}
}

int main(){
	int tt; cin>>tt;
	while(tt--){
		work();
	}
}