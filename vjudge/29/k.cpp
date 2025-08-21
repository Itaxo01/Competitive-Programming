#include <bits/stdc++.h>
using namespace std;


int main(){
	int n; cin>>n;
	int a, b; cin>>a>>b;
	vector<bool> v(a, false);
	for(int i = 0; i<b; i++){
		int k; cin>>k;
		v[k-1] = true;
	}
	int step = -1;
	for(int i = 0; i<n; i++){
		int m; cin>>m;
		int t = m/3;
		int s = 0;
		for(int j = 0; j<m; j++){
			int k; cin>>k;
			s += v[k-1];
		}
		if(step == -1 && s > t) step = i+1;
	}

	cout<<step<<endl;
}