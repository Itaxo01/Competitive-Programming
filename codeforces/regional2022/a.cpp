#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	string s; cin>>s;
	bool a = false;
	int count = 0;
	int sum = 0;
	for(int i = 0; i<n; i++){
		if(a){
			if(s[i] == 'a') count++;
			else {
				if(count > 1)
					sum += count;
				a = false;
				count = 0;
			}
		} else {
			if(s[i] == 'a'){	
				a = true;
				count = 1;
			}
		}
	}
	if(count > 1)
		sum += count;
	cout<<sum<<endl;
}