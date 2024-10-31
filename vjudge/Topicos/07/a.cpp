#include <bits/stdc++.h>
using namespace std;


bitset<101> vs;
bitset<101> dominit;
int arr[101][101];
int dom[101][101];
int a;

void dfs(int u, int del){
	if(u == del) return;
	vs.set(u);
	for(int i = 0; i<a; i++){
		if(arr[u][i]==1 && !vs.test(i)){
			dfs(i, del);
		}
	}
}

void solve(){
	vs.reset();
	dfs(0, -1);
	dominit = vs;

	for(int i = 0; i<a; i++){
		vs.reset();
		dfs(0, i);
		for(int j = 0; j<a; j++){
			if(!vs.test(j) && dominit.test(j)){
				dom[i][j] = 1;
			} else dom[i][j] = 0;
		}
	}
}

int main(){
	int n; cin>>n;
	int c = 1;
	while(n--){
		cin>>a;
		for(int i = 0; i<a; i++){
			for(int j = 0; j<a; j++){
				cin>>arr[i][j];
			}
		}
		solve();
		string s = "+" + string(2*a-1, '-') + "+";
		printf("Case %d:\n", c++);
		cout<<s<<endl;
		for(int i = 0; i<a; i++){
			cout<<"|";
			for(int j = 0; j<a; j++){
				if(dom[i][j] == 1) cout<<"Y|";
				else cout<<"N|";
			}
			cout<<endl;
			cout<<s<<endl;
		}
	}
}