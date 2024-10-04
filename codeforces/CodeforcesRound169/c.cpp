#include <bits/stdc++.h>
#define ll long long

using namespace std;
int main(){
	int n; cin>>n;
	for(int i = 0; i<n; i++){
		int a, b; cin>>a>>b;
		vector<int> v(a);
		for(int j = 0; j<a; j++){
			cin>>v[j];
		}
		sort(v.begin(), v.end(), greater<int>());
		ll A = v[0];
		ll B = 0;
		int anterior = v[0];
		for(int j = 1; j<a; j++){
			if(j%2==1){
				int dif = anterior-v[j];
				v[j]+=min(b, dif);
				b = max(0, b-dif);
				B += v[j];
			}else{
				anterior = v[j];
				A+=v[j];
				} 
		}
		cout<<A-B<<endl;
	}
}