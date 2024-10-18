#include <bits/stdc++.h>


using namespace std;

int main(){
	int n; cin>>n;
	bitset<10> bs; bs.set();
	for(int i = 0; i<n; i++){
		int c; cin>>c;
		bs.reset(c);
	}
	int q; cin>>q;
	for(int i = 0; i<q; i++){
		int a; cin>>a;
		int h, m, s; scanf("%d: %d: %d:", &h, &m, &s);
		cout<<h<<" "<<m<<" "<<s<<endl;
	}
}