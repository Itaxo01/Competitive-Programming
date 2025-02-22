#include <bits/stdc++.h>
using namespace std;

bool first = true;
void work(){
	if(!first) cout<<'\n';
	first = false;
	int m, n; cin>>m>>n;
	vector<vector<int>> hash(m);
	for(int i = 0; i<n; i++){
		int a; cin>>a;
		hash[a%m].push_back(a);
	}
	
	for(int i = 0; i<m; i++){
		printf("%d", i);
		for(int e: hash[i]){
			printf(" -> %d", e);
		}
		printf(" -> \\\n");
	}
}

int main(){
	int n; cin>>n;
	while(n--) work();
}