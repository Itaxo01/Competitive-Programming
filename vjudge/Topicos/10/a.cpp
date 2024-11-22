#include <bits/stdc++.h>
using namespace std;

bitset<20000001> isPrime;
vector<pair<int, int>> primes;

void sieve(){
	isPrime.set();
	isPrime.reset(0);
	isPrime.reset(1);
	for(int p = 2; p*p <= 20000000; p++){
		if(isPrime.test(p)){
			for(int i = p*p; i <= 20000000; i += p){
				isPrime.reset(i);
			}
		}
	}
	for(int p = 2; p <= 20000000; p++){
		if(isPrime.test(p-2) && isPrime.test(p))
			primes.push_back({p-2, p});
	}
}

int main(){
	sieve();
	int a;
	while(cin>>a){
		cout<<"("<<primes[a-1].first<<", "<<primes[a-1].second<<")"<<endl;
	}
}