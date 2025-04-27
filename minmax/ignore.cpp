#include <bits/stdc++.h>
#define MAX 1e9
#define ld long double
using namespace std;
bitset<1000000001> bs;

int main(){
	int count = 0;
	bs.set();
	for(int i = 2; i*i <= MAX; i++){
		for(int p = i*i; p<=MAX; p+=i){
			bs.reset(p);
		}
	}
	for(int i = 2; i <= MAX; i++){
		if(bs.test(i)) count++;
	}
	cout<<count<<" / "<<MAX<<endl;
	cout<<(count/(ld)MAX)*100<<"%\n";
}