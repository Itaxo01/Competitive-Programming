#include <bits/stdc++.h>
#define int long long
using namespace std;

int evaluate(vector<int> &p){
	int sum = 0;
	for(int i = 0; i<p.size(); i++){
		sum += abs(p[i] - (i+1));
	}
	return sum;
}

void work(){
	int n; cin>>n;
	int res = n;
	
	int s = 1;
	for(int i = 3; i < n; i++){
		res += s;
		if(i % 2 == 0) s++;
	}
	cout<<res<<endl;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	while(n--){
		work();
	}	
}