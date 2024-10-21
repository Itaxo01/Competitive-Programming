#include <bits/stdc++.h>

using namespace std;

bool verify(vector<int> &v){
	for(int i = 1; i<v.size(); i++){
		if(v[i-1]>v[i]) return false;
	}
	return true;
}

int main(){
	int n; cin>>n;
	while(n--){
		int a, b; cin>>a>>b;
		vector<int> c(a);
		for(int i = 0; i<a; i++){
			cin>>c[a];
		}
		string s; cin>>s;
		for(int i = 0; i<b; i++){

			int q; cin>>q;
			if(s[q-1] == 'L') s[q-1] = 'R';
			else s[q-1] = 'L';

			
			if(verify(c)) cout <<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
}