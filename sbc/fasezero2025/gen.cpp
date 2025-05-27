#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	cout<<n<<endl;
	for(int i = 1; i<n/2; i++){
		cout<<i<<" ";
	}
	int c = 1;
	for(int i = n/2; i<n; i++){
		cout<<c<<" ";
		c++;
	} cout<<endl;

	// for(int i = 1; i<n; i++){
	// 	// cout<<(char)(rand()%26 + 'a');
	// 	cout<<s[i%26];
	// }
	for(int i = 1; i<n/2; i++){
		cout<<"a";
	}
	for(int i = n/2; i<n; i++){
		cout<<"b";
	}
	cout<<endl;
}