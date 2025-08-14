#include <bits/stdc++.h>
using namespace std;

/* REF : 
GGGgGGG = 0          2
gggggGG = 1        0   5
gGGGGGg = 2          3
ggGGGGG = 3        1   6
GggGgGG = 4          4
GgGGGgG = 5
GGGGGgG = 6
ggGggGG = 7
GGGGGGG = 8
GgGGGGG = 9
*/


map<string, int> m = {
	{"GGGgGGG", 0},
	{"gggggGG", 1},
	{"gGGGGGg", 2},
	{"ggGGGGG", 3},
	{"GggGgGG", 4},
	{"GgGGGgG", 5},
	{"GGGGGgG", 6},
	{"ggGggGG", 7},
	{"GGGGGGG", 8},
	{"GgGGGGG", 9}
};

int solve(string s, int p, int &count){
	if(p == 7) {
		if(m.find(s) != m.end()) {
			count++;
			return m[s];
		}
		return 0;
	}
	if(s[p] == '+' || s[p] == '-') {
		s[p] = 'G';
		int p1 = solve(s, p+1, count);
		s[p] = 'g';
		int p2 = solve(s, p+1, count);
		return p1 + p2;
	} 
	return solve(s, p+1, count);
}
int main(){
	int n; cin>>n;
	string res = "";
	for(int i =0 ; i<n; i++){
		string s; cin>>s;
		int count = 0;
		int num = solve(s, 0, count);
		if(count == 1) res.push_back(num + '0');
		else {
			res.push_back('*');
		} 
	}
	cout<<res<<endl;
}