#include <bits/stdc++.h>
using namespace std;



int main(){
	int a; cin>>a;
	vector<int> v(32, 0);
	for(int i = 0; i<a; i++){
		int c; cin>>c;
		for(int j = 0; j<32; j++){
			if(c & (1<<j)) v[j]++;
		}
	}
	for(int i = 0; i<a; i++){
		int c = 0;
		for(int j = 31; j>=0; j--){
			if(v[j]!=0){
				c+= (1<<j);
				v[j]--;
			}
		}
		if(!i) cout<<c;
		else cout<<" "<<c;
	}
	cout<<endl;
}