#include <bits/stdc++.h>
#define ld long double
using namespace std;
bitset<100005> bs;
void sieve(int n, vector<int> &primos){
	bs.set();
	for(int i = 2; i*i<n; i++){
		for(int p = i*i; p<n; p+=i){
			bs.reset(p);
		}
	}
	for(int i = 2; i<=n; i++){
		if(bs[i]) primos.push_back(i);
	}
}

int main(){
	int n; cin>>n;

	ld W = 0;
	vector<ld> w(n+1);
	for(int i = 0; i<n; i++){
		int b; cin>>b;
		W += b;
		w[i+1] = b;
	}
	for(int i = 1; i<=n; i++){
		w[i] = w[i]/(ld)W;
	}

	vector<int> primos;
	sieve(n, primos);
	for(int p: primos){
		for(int i = 1; i*p<=n; i++){
			w[i*p] += w[i];
		}
	}
	vector<int> s(n+1);
	for(int i = 1; i<=n; i++) {
		s[i] = 1/w[i];
	}

	for(int p: primos){
		for(int i = n/p; i>=1; i--){
			s[i*p] -= s[i];			
		}
	}
	int sum = 0;
	for(int i = 1; i<=n; i++) sum+=s[i];
	cout<<sum<<endl;
}