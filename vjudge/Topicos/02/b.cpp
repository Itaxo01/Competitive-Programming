#include <bits/stdc++.h>


using namespace std;
int main(){
	int a;
	vector<int> v;
	while(cin>>a){
		v.push_back(a);
		sort(v.begin(), v.end());
		if(v.size() & 1){
			cout<<v[(v.size()/2)-1]<<endl;
		}else cout<<(v[v.size()/2]+v[(v.size()/2)-1])/2<<endl;
	}
}