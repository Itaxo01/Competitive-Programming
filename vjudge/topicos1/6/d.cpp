#include <bits/stdc++.h>
#define no {cout<<"N"<<endl; return 0;}
#define yes {cout<<"Y"<<endl; return 0;}
using namespace std;


int main(){
	int n; cin>>n;
	vector<int> freq(1e5+10, 0);
	for(int i = 0; i<n; i++){
		int a; cin>>a;
		freq[a]++;
	}
	int c = 0;
	for(int i = 0; i<1e5+10; i++){
		freq[i] +=c;
		c = freq[i]/2;
		freq[i] %= 2;
	}
	int count = 0;
	for(int e:freq){
		if(e == 1) count++;
	}
	if(count == 1 && n > 1) yes
	else if(count == 2) yes
	else no; 

}