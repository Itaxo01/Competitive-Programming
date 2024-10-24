#include <bits/stdc++.h>
#define int long long
using namespace std;

int zero = 0;
int test(int a, int b, vector<int> &v){
	for(int e: v){
		b -= max(zero, a-e);
		if(b<0) return b;
	}
	return b;
}

void work(){
	int a, b; cin>>a>>b;
	vector<int> v(a);
	for(int i = 0; i<a; i++){
		cin>>v[i];
	}

	int i = 0, f = 1e12;
	int menor = INT_MAX;
	int menor_n = 0;
	while(i<f){
		int m = (i+f)/2;
		int t = test(m, b, v);
		if(t>= 0 && t<menor){
			menor = t;
			menor_n = m;
		}
		if(t>0) i = m+1;
		else f = m-1; 
	}
	cout<<menor_n<<endl;
}

signed main(){
	int n; cin>>n;
	while(n--){
		work();
	}
}