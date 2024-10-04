#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while(cin>>n){
		vector<int> v(n);
		for(int i = 0; i<n; i++){
			cin>>v[i];
		}
		sort(v.begin(), v.end());
		int target; cin>>target;
		int id = 0;
		int menor = INT_MAX;

		for(int i = 0; i<n; i++){
			auto it = lower_bound(v.begin(), v.end(), target-v[i]);
			if(it != v.end() && *it == target-v[i] && it != v.begin()+i){
				if(abs(v[i] - *it) < menor){
					menor = abs(v[i] - *it);
					id = i;
				}
			}
		}

		int a = min(target-v[id], v[id]);
		int b = max(target-v[id], v[id]);
		printf("Peter should buy books whose prices are %d and %d.\n\n", a, b);
	}	
}