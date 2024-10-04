#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	
	for(int i = 0; i<n; i++){
		int a; cin>>a;
		vector<int> v(a);
		for(int j = 0; j<a; j++){
			cin>>v[j];
		}
		if(v[a-1]>=v[0]+v[1]) cout<<"1 2 "<<a<<endl;
		else cout<<-1<<endl;
	}
}