#include <bits/stdc++.h>
#define int long long

using namespace std;
signed main(){
	int n; cin>>n;
	deque<int> v(n);
	for(int i = 0; i<n; i++){
		cin>>v[i];
	}

	int sum = 0;
	while(v.size()>1){
		
		int dif = INT_MAX;
		int id = 0;
		for(int i = 1; i<v.size(); i++){
			if(v[i]+v[i-1] < dif){
				dif = v[i]+v[i-1];
				id = i;
			}
		}
		sum+=dif;
		v.erase(v.begin()+id);
		v[id-1] = dif;
	}
	cout<<sum<<endl;
}