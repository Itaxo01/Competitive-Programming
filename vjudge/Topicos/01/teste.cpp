#include <bits/stdc++.h>
using namespace std;
map<long long, long long> mem;

long long fib(long long n){
	if(mem.find(n)!=mem.end()) return mem[n];
	return mem[n] = fib(n-1)+fib(n-2);
}

long long fastpow(long long n){
	return (long long)1 << n;
}

int main(){
	mem[0] = 0;
	mem[1] = 1;
	double d = 1.618033988749895;
	double a = 2;
	for(int i = 1; i<63; i++){
		cout<<a<<endl;
		a *=d;
	}
}
