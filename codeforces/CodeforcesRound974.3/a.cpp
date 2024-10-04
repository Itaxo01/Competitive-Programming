#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	while(n--){
		int a, b; cin>>a>>b;
		int total = 0;
		int counter = 0;
		for(int i = 0; i<a; i++){
			int c; cin>>c;
			if(c==0){
				if(total>0){
					total--;
					counter++;
				}
			}
			else if(c>=b){
				total+=c;
			}
		}
		cout<<counter<<endl;
	}
}