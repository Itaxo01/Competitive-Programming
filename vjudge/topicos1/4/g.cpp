#include <bits/stdc++.h>
#define ld long double
#define EPS 1e-9
using namespace std;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b; cin>>a>>b;
	long double pA = 0, pB = 0;
	for(int i = 0 ; i<a; i++){
		int k; cin>>k;
		pA += (k+1)/(ld)2;
	}
	for(int i = 0 ; i<b; i++){
		int k; cin>>k;
		pB += (k+1)/(ld)2;
	}
	if(fabs(pA-pB) < EPS) cout<<"TIED"<<endl;
	else if(pA > pB) cout<<"ALICE"<<endl;
	else cout<<"BOB"<<endl;
}