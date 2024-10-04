#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, f; cin>>n>>f;
	int sum = f;
	bool win = true;
	for(int i = 0; i<n; i++){
		int a, b; cin>>a>>b;
		if(f>=max(a, b)) f+=max(a, b);
		else if(f>=min(a, b)) f+=min(a, b);
		else win = false;
	}
	if(win) cout<<"S"<<endl;
	else cout<<"N"<<endl;
}