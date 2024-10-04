#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	while(n--){
		int m; cin>>m;
		vector<int> v(m);
		for(int i = 0; i<m; i++){
			cin>>v[i];
		}
		for(int i = 0; i<m-2; i++){
			v[m-2] -= v[i];
		}
		v[m-1] = v[m-1] - v[m-2];
		
		cout<<v[m-1]<<endl;

	}
	return 0;
}