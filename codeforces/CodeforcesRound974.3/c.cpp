#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n; cin>>n;
	while(n--){
		int a; cin>>a;
		int total = 0;
		vector<int> v(a);
		for(int i = 0; i<a; i++){
			int b; cin>>b;
			total+=b;
			v[i] = b;
		}
		sort(v.begin(), v.end());
		double average = total/(double)a;
		int meio;
		if(a & 1) meio = v[(v.size()/2)];
		else meio = v[(v.size()/2)];

		if(a <= 2) cout<<-1<<endl;
		else if((average/(double)2)>meio) cout<<0<<endl;
		else{
			int x = (2*meio*(a)-total)+1;
			cout<<x<<endl;
		}

	}
}