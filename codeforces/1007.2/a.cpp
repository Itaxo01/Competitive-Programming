#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>> 
using namespace std;

void work(){
	int a; cin>>a;
	if((a-1)%3 == 0) cout<<"YES";
	else cout<<"NO";
	cout<<endl;
}


signed main(){
	int tt; cin>>tt;
	while(tt--)
		work();
	return 0;
}