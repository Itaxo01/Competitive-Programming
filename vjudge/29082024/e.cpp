#include <bits/stdc++.h>


using namespace std;

vector<int> divisors(int n){
	vector<int> div;
	int sqr = floor(pow(n, 0.5));
	while(n%2==0){
		div.push_back(2);
		n/=2;
	}
	while(n%3==0){
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
	int n; cin>>n;
	vector<int> div = divisors(n);
	cout<<div[0];
	for(int i = 1; i<div.size(); i++){
		cout<<"x"<<div[i];
	}
	cout<<endl;
}