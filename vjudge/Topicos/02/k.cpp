#include <bits/stdc++.h>

using namespace std;
int main(){
	int c = 1;
	while(true){
		int n; cin>>n;
		if(n==0) break;
		cout<<"Case "<<c<<":"<<endl; c++;
		vector<int> v;
		set<int> s;
		for(int j = 0; j<n; j++){
			int a; cin>>a;
			for(int i = 0; i<v.size(); i++){
				s.insert(a+v[i]);
			}
			v.push_back(a);
		}
		int m; cin>>m;
		for(int i = 0 ; i <m; i++){
			int b; cin>>b;
			auto it = s.lower_bound(b);
			auto it1 = it;
			if(it!=s.begin())
				it1--;
			int menor = 0;
			if(abs(b-*it)>abs(b-*it1))
				menor = *(it1);
			else
				menor = *(it);
			cout<<"Closest sum to "<<b<<" is "<<menor<<"."<<endl;
		}
	}
	return 0;
}