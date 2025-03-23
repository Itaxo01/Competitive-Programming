#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	int n = 1e5;
	int q = 1e5;
	int v = 1e6;
	cout<<n<<endl;
	for(int i = 1; i<=n; i++){
		cout<<i<<" ";
	}
	cout<<q<<endl;
	for(int i = 1; i<=q; i++){
		cout<<rand()%v<<endl;
	}
}