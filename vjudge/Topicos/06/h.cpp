#include <bits/stdc++.h>

using namespace std;
string s, t;

int edit(int s1, int t1, vector<vector<int>> &memo){
	if(t1 == 0) return s1;
	if(s1 == 0) return t1;
	if(memo[s1][t1] != -1){
		return memo[s1][t1];
	}
	if(s[s1-1] == t[t1-1]){
		return memo[s1][t1] = edit(s1-1, t1-1, memo);
	}
	return memo[s1][t1] = 1 + min({edit(s1, t1 - 1, memo),
								edit(s1 - 1, t1, memo),
								edit(s1 - 1, t1-1, memo)});
}

int main(){
	int n; cin>>n;
	while(n--){
		cin>>s>>t;
		vector<vector<int>> memo(s.size() + 1, vector<int>(t.size() + 1, -1));
		cout<<edit(s.size(), t.size(), memo)<<endl;
	}
}