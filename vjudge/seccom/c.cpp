#include <bits/stdc++.h>
using namespace std;


int main(){
	int a, b; cin>>a>>b;
	int anterior = 0;
	vector<int> duplos;
	for(int i = 0; i<a; i++){
		int c; cin>>c;
		if(c == anterior){
			duplos.push_back(i-1);
			duplos.push_back(i);
		}
		anterior = c;
	}
	if(duplos.size() == 0) cout<<a<<endl;
	else {
		int dif = duplos[0]+1;
		for(int i = 1; i<duplos.size(); i++){
			dif = max(dif, duplos[i] - duplos[i-1]+1);
		}
		dif = max(dif, a-duplos[duplos.size()-1]);
		cout<<dif<<endl;
	}
}