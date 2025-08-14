#include <bits/stdc++.h>
#define no {cout<<"N"<<endl; return 0;}
#define yes {cout<<"Y"<<endl; return 0;}
using namespace std;


int main(){
	int n; cin>>n;
	double x; cin>>x;
	// vector<int> v(2e5+5);
	vector<pair<int, int>> seg(n);
	for(auto &[a, b]:seg) cin>>a>>b;
	// v[a]++;
		// v[a+b+1]--;
	// int s = 0;
	// vector<bool> seg(2e5+5, false);
	// for(int i = 0; i<2e5+5; i++){
	// 	s+=v[i];
	// 	if(s>0) seg[i] = true;
	// }
	int c = INT_MAX, t = 0;
	for(int i = 0; i<=480; i++){
		int conf = 0;
		for(auto &[D, S]: seg){

			int l = ceil((D-i)/x); // k precisa ser maior igual a isso
			int r = floor((D+S-i)/x); // k precisa ser menor que isso
			if(r >= 0 && l <= r){
				conf += (r-max(l, 0)+1);
			}
		}
		if(c > conf) c = conf, t = i;
	}
	cout<<t<<" "<<c<<endl;

}