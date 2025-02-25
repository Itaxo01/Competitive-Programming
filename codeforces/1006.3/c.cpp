#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
using namespace std;

void work(){
	int a, b; cin>>a>>b;
	vector<int> v(a, 0);
	int num = 0;

	for(int i = 0; i<a; i++){
		if((i | b) == b) {
			v[i] = i;
			num |= i;
		}
	}
	
	if(num != b) v[a-1] = b;
	for(int i = 0; i<a; i++){
		if(i) cout<<" ";
		cout<<v[i];
	}
	cout<<endl;
}


signed main(){
    int tt; cin>>tt;
    while(tt--)
        work();

    return 0;
}