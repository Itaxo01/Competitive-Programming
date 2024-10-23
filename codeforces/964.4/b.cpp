#include <bits/stdc++.h>


using namespace std;

void work(){
	int a, b, c, d; cin>>a>>b>>c>>d;
	int res = 0;
	if(a>c && b>d) res++;
	if(b>c && a>d) res++;
	if(a>d && b>c) res++;
	if(b>d && a>c) res++;
	// 02 13
	// 12 03
	// 03 12
	// 13 02

	cout<<res<<endl;
}

int main(){
	int n; cin>>n;
	while(n--){
		work();
	}
}