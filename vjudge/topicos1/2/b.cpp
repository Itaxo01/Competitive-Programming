#include <bits/stdc++.h>
using namespace std;


int main(){
	int a; cin>>a;
	vector<int> v(3*a);
	for(int i =0 ; i<3*a; i++){	
		cin>>v[i];
	}
	int sum_a = 0, sum_b = 0;
	sort(v.rbegin(), v.rend());
	for(int i = 0; i<3*a; i+=3){
		sum_a+=v[i];
		sum_b+=v[i+1];
	}
	int sum_ra = 0, sum_rb = 0;
	for(int i = 3*a-1; i>=0; i-=3){
		sum_a+=v[i];
		sum_b+=v[i-1];
	}
	if(sum_a != sum_b || sum_ra != sum_rb) cout<<"Y";
	else cout<<"N";
	cout<<endl;
}