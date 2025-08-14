#include <bits/stdc++.h>
using namespace std;

int main(){
	int d, c, r; cin>>d>>c>>r;

	vector<int> v1(c), v2(r);
	for(int &e: v1) cin>>e;
	for(int &e: v2) cin>>e;

	int k = 0;
	int p1 = 0, p2 = 0;
	while(true){
		if(p1 < c && d >= v1[p1]){
			d -= v1[p1++];
			k++;
		} else if(p2 < r){
			d += v2[p2++];
			k++;
		} else break;
	}
	cout<<k<<endl;
}