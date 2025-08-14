#include <bits/stdc++.h>
#define no {cout<<"N"<<endl; return 0;}
#define yes {cout<<"Y"<<endl; return 0;}
#define int long long
using namespace std;


int kedane(vector<int> &v, int m){
	int n = v.size();
	pair<int, int> a = {0, 0}; // sum, initial position
	int p = 0, s = 0;
	for(int i = 0; i<n; i++){
		s += v[i] - m;
		if(s < 0) s = 0, p = i+1;
		else a = max(a, make_pair(s, p));
	}
	return a.second;
}

signed main(){
	int n; cin>>n;
	vector<int> v_(n), v1(2*n);
	int s = 0;
	for(int &e: v_) cin>>e, s+=e;
	int m = s/n;
	for(int i = 0; i<2*n; i++){
		v1[i] = v_[i%n];
	}
	vector<int> v2(v1.rbegin(), v1.rend());
	int l = kedane(v1, m);
	int r = kedane(v2, m); 
	int s1 = 0, s2 = 0;
	int c1 = 0, c2 = 0;
	for(int i = l; i<n+l; i++){
		s1 += c1;
		if(v1[i] < m){
			if(c1 >= m-v1[i]) c1 = c1 - m + v1[i], v1[i] = m;
		}
		if(v1[i] > m) c1 += v1[i]-m, v1[i] = m;
	}
	for(int i = r; i<n+r; i++){
		s2 += c2;
		if(v2[i] < m)
			if(c2 >= m-v2[i]) c2 -= m-v2[i], v2[i] = m;
		if(v2[i] > m) c2 += v2[i]-m, v2[i] = m;
	}

	for(int i = l; i<n+l; i++){
		s1 += c1;
		if(v1[i] < m){
			if(c1 >= m-v1[i]) c1 = c1 - m + v1[i], v1[i] = m;
		}
		if(v1[i] > m) c1 += v1[i]-m, v1[i] = m;
	}
	for(int i = r; i<n+r; i++){
		s2 += c2;
		if(v2[i] < m)
			if(c2 >= m-v2[i]) c2 -= m-v2[i], v2[i] = m;
		if(v2[i] > m) c2 += v2[i]-m, v2[i] = m;
	}

	// for(int i = l; i<n+l; i++){
	// 	if(v1[i] != m) cout<<"F"<<endl;
	// }
	// for(int i = r; i<n+r; i++){
	// 	if(v2[i] != m) cout<<"F"<<endl;
	// }
	// cout<<s1<<" "<<s2<<endl;

	
	cout<<min(s1, s2)<<endl;
}