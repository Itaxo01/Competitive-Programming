#include <bits/stdc++.h>
#define int long long
using namespace std;

int test(int a, int h, vector<pair<int, int>> &m){
	for(int i = 0; i<m.size(); i++){
		h-= m[i].first;
		h-= m[i].first*(a/m[i].second);
		if(h<=0) return h;
	}
	return h;
}

void work(){
	int h, a; cin>>h>>a;
	vector<pair<int, int>> at(a);
	for(int i = 0; i<a; i++){
		cin>>at[i].first;
	}
	for(int i = 0; i<a; i++){
		cin>>at[i].second;
	}

	int i = 0, f = 5e11;
	while(i<f){
		int m = (i+f)/2;
		int t = test(m, h, at);
		if(t <= 0) f = m;
		else i = m+1;
	}
	cout<<1+(i+f)/2<<endl;

}

signed main(){
	int n; cin>>n;
	while(n--){
		work();
	}
}