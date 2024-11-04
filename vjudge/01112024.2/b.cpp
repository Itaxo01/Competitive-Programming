#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, c, d; cin>>a>>b>>c>>d;
	if(a>=c) cout<<0<<endl;
	else{
		double x = floor((c-a)/(double)(b-d));
		if(x<0) cout<<-1<<endl;
		else cout<<x+1<<endl;
	}
}