#include <bits/stdc++.h>
using namespace std;


int n;
void solve(vector<int> &v, vector<int> &d){
	stack<int> t;
	vector<int> m(n);
	for(int i = n-1; i>=0; i--){
		if(!t.empty()){
			while(!t.empty() && v[i] > v[t.top()]) t.pop();
		}
		if(!t.empty()) m[i] = t.top();
		else m[i] = -1;
		t.push(i);
	}
	for(int i = 0; i<n; i++){
		int l = i+1;
		int r = l + (m[i]-i-1)/2;
		if(m[i] != -1){
			d[l]++, d[r]--;
		} else {
			d[l]++;
		}
	} 
}

int main(){
	cin>>n;
	vector<int> v(n);
	for(int &e: v) cin>>e;

	vector<int> v2 = v;
	reverse(v2.begin(), v2.end());
	vector<int> d1(n+2), d2(n+2);
	solve(v, d1);
	solve(v2, d2);

	for(int i = 1; i<n; i++){
		d1[i]+= d1[i-1];
		d2[i]+= d2[i-1];
		
	}
	for(int i = 0; i<n; i++){
		if(i) cout<<" ";
		cout<<d1[i] + d2[n-i-1];
	} cout<<endl;


}