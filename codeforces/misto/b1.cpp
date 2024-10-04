#include <bits/stdc++.h>

using namespace std;

int main(){
	long long a, b, c;
	cin>>a>>b>>c;
	a*=1e13;
	long long d = a/b;
	int i = 1;
	int pos = -1;
	while(d>0){
		if(d%10 == c) pos = i;
		i++;
		d/=10;
	}
	if(pos == -1) cout<<pos<<endl;
	else cout<<i-pos<<endl;
}