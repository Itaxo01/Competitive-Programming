#include <bits/stdc++.h>

using namespace std;

vector<int> divisores(int n){
	vector<int> div;
	int sqr = floor(pow(n, 0.5));
	while(n%2==0){
		div.push_back(2);
		n/=2;
	}
	while(n%3==0){
		int s1 = 0;
		div.push_back(3);
		n/=3;
	}
	for(int i = 5; i<sqr; i+=6){
		if(n%i==0){
			while(n%i==0){
				div.push_back(i);
				n/=i;

			}
		}else if(n%(i+2)==0){
			while(n%(i+2)==0){
				div.push_back(i+2);
				n/=(i+2);
			}
		}
	}
	return div;
}



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	for(int i = 0; i<n; i++){
		int a; cin>>a;
		vector<int> div = divisores(a);

		// int b = divisores(a);
		// if(b==a) cout<<a<<" perfecto"<<endl;
		// else{
		// 	int c = divisores(b);
		// 	bool r = false;
		// 	bool ab = false;
		// 	if(c==a) r = true;
		// 	if(b>a) ab = true;
		// 	if(ab && r) cout<<a<<" romantico abundante"<<endl;
		// 	else if(ab) cout<<a<<" abundante"<<endl;
		// 	else if(r) cout<<a<<" romantico"<<endl;
		// 	else cout<<a<<" complicado"<<endl;
		// }
	}
}