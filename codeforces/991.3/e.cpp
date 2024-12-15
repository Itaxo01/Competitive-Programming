#include <bits/stdc++.h>
using namespace std;


int solve(string &a, string &b, string &c, int pos_a, int pos_b, int pos_c, int count){
	for(int i = pos_c; i < c.size(); i++){
		if(c[i] != a[pos_a] && c[i] != b[pos_b]){
			return min(solve(a, b, c, pos_a+1, pos_b, i+1, count+1),
							solve(a, b, c, pos_a, pos_b+1, i+1, count+1));
		} else if(c[i] == a[pos_a] && c[i] == b[pos_b]){
			return min(solve(a, b, c, pos_a+1, pos_b, i+1, count),
							solve(a, b, c, pos_a, pos_b+1, i+1, count));
		} else if(c[i] == a[pos_a]){
			return min(solve(a, b, c, pos_a+1, pos_b, i+1, count),
							solve(a, b, c, pos_a, pos_b+1, i+1, count+1));
		} else if(c[i] == b[pos_b]){
			return min(solve(a, b, c, pos_a, pos_b+1, i+1, count),
							solve(a, b, c, pos_a+1, pos_b, i+1, count+1));
		}
	}
	return count;
}

void work(){
	string a, b, c; cin>>a>>b>>c;
	cout<<solve(a, b, c, 0, 0, 0, 0)<<endl;
}

int main(){
	int tt; cin>>tt;
	while(tt--){
		work();
	}
}