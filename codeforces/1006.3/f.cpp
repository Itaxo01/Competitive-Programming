#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
using namespace std;

void work(){
	int a, b; cin>>a>>b;
	a--; 
	for(int i = 0; i<=a; i++){
		if(i) cout<<" ";
		cout << (((i & a) == i) ? b : 0);
	} cout<<endl;
}


signed main(){
    int tt; cin>>tt;
    while(tt--)
        work();
    return 0;
}