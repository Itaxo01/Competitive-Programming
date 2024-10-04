#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	for(int i = 0; i<n; i++){
		int a; cin>>a;
		int ones=0, zeros=0;
		for(int j = 0; j<a; j++){
			char c; cin>>c;
			if(c-'0'==0) zeros++;
			if(c-'0'==1) ones++;
		}
		int sqr = (int)sqrt(a);
		if(sqr*sqr == a){
			int meio = pow((sqrt(a)-2), 2);
			if(zeros==meio and ones==a-meio) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		else cout<<"No"<<endl;
	}
}