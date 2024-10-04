#include <bits/stdc++.h>

using namespace std;
int main(){
	int n; cin>>n;
	for(int i = 0; i<n; i++){
		int a, b; cin>>a>>b;
		int c, d; cin>>c>>d;
		int count = 0;
		int lb = min(a, c);
		int ub = max(b, d);
		if((b<c) || (d<a)) count = 1;
		if((b<d && b>=c) || (b>d && d>=a)) count++;
		for(int i = lb+1; i<=ub; i++){
			if((i>=a && i<=b) && (i>=c &&i<=d)) count++;
		}
		cout<<count<<endl;
	}
}