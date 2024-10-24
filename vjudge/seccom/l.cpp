#include<bits/stdc++.h>
#define ll long long
using namespace std;

int gcd(int a, int b){
	if (a == 0) return b;
	return gcd(b%a, a);
}


int main() {
	int t;cin>>t;
	int cases = 1;
	while(t--){
		int a,b,c;cin>>a>>b>>c;
		abs(a); abs(b); abs(c);
		if (c%gcd(a,b)){
			cout<<"Cases "<<cases++<<": No"<<endl;
		}else{	
			cout<<"Cases "<<cases++<<": Yes"<<endl;
		}
		
	}
	return 0;
}