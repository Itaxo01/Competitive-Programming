#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define RAND_MAX 1e12
using namespace std;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	unordered_map<int, int> m;
	int a, b; cin>>a>>b;
	vector<int> v(b);
	int sum = 0;
	
	for(int i = 0; i<b-1; i++){
		v[i] = rand()%MOD;
		sum+=v[i];
	}
	v[b-1] = -sum;

	sum = 0;
	int max_dist = 0;
	m[0] = -1;
	for(int i = 0; i<a; i++){
		int c; cin>>c;
		sum += v[c-1];

		if(m.find(sum) != m.end()){
			max_dist = max(max_dist, i-m[sum]); 
		} else m[sum] = i;
	}

	printf("%lld\n", max_dist);
}