#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
using namespace std;

void work(){
    int a, b; cin>>a>>b;
	bool first = true;
	if(a & 1) {
		for(int i = 0; i<a; i++){
			if(i == 0 || i == a-1){
				if(first){
					first = false;
					cout<<b;
				} else{
					cout<<" "<<b;
				}
			} else {
				if(first){
					first = false;
					cout<<"0";
				} else{
					cout<<" "<<"0";
				}
			}
		}
	}
	else {
		for(int i = 0; i<a; i++){
			if(first){
				first = false;
				cout<<b;
			} else{
				cout<<" "<<b;
			}
		}
	}
	cout<<endl;
}


signed main(){
    int tt; cin>>tt;
    while(tt--)
        work();

    return 0;
}