#include <bits/stdc++.h>
#define int long long
using namespace std;
int a, b;

int test(int i){
	int s1 = ((b+b+i-1)*(i))/2;
	int s2 = ((b+i+b+a-1)*(a-i))/2;
	return abs(s1-s2);
}

signed main(){
	int n; cin>>n;
	while(n--){
		cin>>a>>b;
		int i = 0, f = a+1;
		int m1 = 0, m2 = 0;
		while(i<f){
			m1 = (2*i+f)/3;
			m2 = (i+2*f)/3;
			int t1 = test(m1);
			int t2 = test(m2);
			// cout<<m1<<" "<<t1<<", "<<m2<<" "<<t2<<endl;
			if(t1 == t2){
				i = m1+1;
				f = m2;
			}
			if(t1 < t2)	f = m2;
			else i = m1+1;
		}
		cout<<test((2*i+f)/3)<<endl;
	}
}