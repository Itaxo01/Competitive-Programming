#include <bits/stdc++.h>

using namespace std;

void work(){
	vector<int> terms;
	int v; cin>>v;
	int count = 0;
	int n = 10;
	while(v>0){
		while(v%n != 0){
			terms.push_back(v%n);
			v-=v%n;
			count++;
		}
		n*=10;
	}
	cout<<count<<endl;
	bool first = true;
	for(auto e: terms){
		if(first){
			first = false;
			cout<<e;
		}
		else cout<<" "<<e;
	}
	cout<<endl;
}

int main(){
	int n; cin>>n;
	while(n--){
		work();
	}
}