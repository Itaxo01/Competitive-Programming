#include <bits/stdc++.h>
using namespace std;



int main(){
	int n, d; cin>>n>>d;
	vector<pair<int, int>> v(n);
	for(int i = 0; i<n; i++){
		int k; cin>>k;
		v[i] = make_pair(k, i);
	}
	sort(v.rbegin(), v.rend());

	int p = 0;

	if(v[0].first == 0) cout<<-1<<endl;
	else if(v[1].first == 0 && v[0].first < d) cout<<-1<<endl;
	else{
		int k = 0;
		for(int i = 0; i<d; i++){
			if(k == v[p].first) k = 0, p = (p+1)%2;
			cout<<v[p].second+1<<" ";
			k++;
		}
		cout<<endl;
	}

	
}