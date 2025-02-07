#include <bits/stdc++.h>
using namespace std;

bool work(){
	int n; cin>>n;
	map<int, int> a;
	map<int, int> b;
	for(int i = 0; i<n; i++){
		int c; cin>>c;
		a[c]++;
	}
	for(int i = 0; i<n; i++){
		int c; cin>>c;
		b[c]++;
	}
	if(a.size() > 2 || b.size() > 2) return true;
	if(a.size() == 1 || b.size() == 1) return false;
	return true;
}

int main(){
	int tt; cin>>tt;
	while(tt--) {
		if(work()) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}