#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c, d; cin>>a>>b>>c>>d;
	if(b < a*c || b > a*d) cout<<"N"<<endl;
	else cout<<"S"<<endl;
}