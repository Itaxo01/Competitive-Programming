#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	int counter = 0;
	multiset<int> s;
	for(int i = 0; i<n; i++){
		int a; cin>>a;
		auto it = s.find(a);
		if(it == s.end()){
			counter++;
			s.insert(a-1);
		}else{
			s.erase(it);
			if(*it>1) s.insert((*it)-1);
		}
	}
	cout<<counter<<endl;
}