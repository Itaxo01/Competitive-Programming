#include <bits/stdc++.h>
using namespace std;

struct custom_hash{
	int operator()(vector<int> &v){
		return 0;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b; cin>>a>>b;
	unordered_map<vector<int>, int, custom_hash> m;
}