#include <bits/stdc++.h>

using namespace std;

void work(){
	int a, b; cin>>a>>b;
	if(b>a) cout<<"NO"<<endl;
	else {
		int c = a/b;
		int r = a%b;
		if(r == 0){
			cout <<"YES"<<endl;
			for(int i = 0; i<b; i++){
				if(!i) cout<<c;
				else cout<<" "<<c;
			} cout<<endl;
			return;
		}
		vector<int> v(b); for(int i = 0; i<b; i++) v[i] = c;
		int i = 0;
		while(r>0){
			v[i++]++;
			r--;
		}
		if(v[0] & 1){
			i = 0;
			while(i<v.size() && v[i] & 1) i++;
			if((v.size()-i) % 2 == 0){
				for(int j = i; j<v.size(); j+=2){
					v[j]++; v[j+1]--;
				}
			} else{
				cout<<"NO"<<endl;
				return;
			}
		} else {
			i = 0;
			while(i<v.size() && v[i] % 2 == 0) i++;
			if((v.size()-i) % 2 == 0 && v[i]>1){
				for(int j = i; j<v.size(); j+=2){
					v[j]++; v[j+1]--;
				}
			} else{
				cout<<"NO"<<endl;
				return;
			}
		}
		cout<<"YES"<<endl;
		for(int i = 0; i<v.size(); i++){
			if(!i) cout<<v[i];
			else cout<<" "<<v[i];
		} cout<<endl;
	}
}

int main(){
	int n; cin>>n;
	while(n--){
		work();
	}
}