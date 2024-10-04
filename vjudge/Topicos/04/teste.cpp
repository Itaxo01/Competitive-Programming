#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	int a; cin>>a;
	int anterior = 0;
	for(int i = 0; i<a; i++){
		int b; cin>>b;
		cout<<b-anterior<<" ";
		anterior = b;
	}
	cout<<endl;
}