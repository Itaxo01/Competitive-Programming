#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll fib[100] = {1, 1};
int A[1000];

void solve(ll n, int pos, int count, bool &existe){
	if(existe) return;
	if(n==1){
		for(int i = 0; i<count; i++){
			for(int j = 0; j<A[i]; j++){
				cout<<"A";
			}
			cout<<"B";
		}
		existe = true;
		return;
	}

	for(int i = pos; i>1; i--){
		ll temp = n%fib[i];
		if(!temp){
			A[count] = i-1;
			solve(n/fib[i], i, count+1, existe);
		}
	}

}


int main(){
	ll n; cin>>n;
	int maior_fib;
	memset(A, 0, 1000);
	for(int i = 2; i<80; i++){
		fib[i] = fib[i-1]+fib[i-2];
		if(fib[i]>n){
			maior_fib = i-1;
			break;
		}
	}
	bool existe = false;
	if(n==1) cout<<"A";
	else solve(n, maior_fib, 0, existe);
	if(!existe) cout<<"IMPOSSIBLE";
	cout<<endl;
}