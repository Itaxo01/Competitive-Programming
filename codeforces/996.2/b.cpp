#include <bits/stdc++.h>
#define int long long
using namespace std;

void work(){
	int n; cin>>n;
	vector<int> a(n), b(n);
	int positive = -1;
	int soma = 0;
	pair<bool, bool> zeros = {false, false};
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}for(int i = 0; i < n; i++){
		cin>>b[i];
	}
	for(int i = 0; i<n; i++){
		int c = b[i] - a[i];
		soma += c;
		if(c > 0) {
			if(positive == -1) positive = c;
			else{
				cout<<"NO"<<endl;
				return;
			}
		}
	}
	if(positive == -1){
		for(int i = 0; i<n; i++){
			int c = b[i] - a[i];
			if(c == 0 && !zeros.first) zeros.first = true;
			else if(c == 0 && zeros.first && !zeros.second) zeros.second = true;
			else if(c == 0 && zeros.first && zeros.second){
				cout<<"NO"<<endl;
				return;
			}
		}
	}
	if(zeros.first && !zeros.second){
		cout<<"NO"<<endl;
		return;
	}
	int fator = n-2;
	if(fator != 0 && soma % fator != 0){
		cout<<"NO"<<endl;
		return;
	}
	cout<<"YES"<<endl;
	
}


signed main(){
	int tt; cin>>tt;
	while(tt--){
		work();
	}
}