#include <bits/stdc++.h>
using namespace std;


void work(){
	int a, b; cin>>a>>b;
	int count = 0;
	int sum = 0;
	for(int i = 0; i<a; i++){
		string s; cin>>s;
		sum += s.size();
		if(sum <= b) count++;
	}
	cout<<count<<endl;
}

int main(){
	int tt; cin>>tt;
	while(tt--) work();
}