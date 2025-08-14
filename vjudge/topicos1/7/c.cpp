#include <bits/stdc++.h>
using namespace std;


int main(){
	int c, n; cin>>c>>n;
	vector<int> v(n);
	for(int &e: v) cin>>e;

	int i = 0;
	int res = 51;
	int last = -51;
	while(i + c < n){
		if(v[i] < last) {
			i++;
			continue;
		}
		int m = i;
		for(int k = i+1; k<min(n, i+c+1); k++){
			if(v[k] > v[m]) m = k;
		}
		i = m;
		res = min(res, v[m]);
		last = min(v[m], last);
		i++;
	}
	cout<<res<<endl;
}