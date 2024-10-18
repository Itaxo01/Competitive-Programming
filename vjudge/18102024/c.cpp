#include <bits/stdc++.h>
using namespace std;
bitset<5001> prime;
int ct[5001];

void sieve(){
	prime.reset(0);
	prime.reset(1);
	
	for(int i = 2; i<=5000; i++){
		if(prime[i]){
			for(int j = 2*i; j<=5000; j+=i){
				prime.reset(j);
				ct[j]++;
			}
		}
	}
}


int main(){
	int n; cin>>n;
	memset(ct, 0, sizeof(ct));
	prime.set();
	sieve();
	int sum = 0;
	for(int i = 1; i<=n; i++)
		if(ct[i]==2) sum++;
	cout<<sum<<endl;
}