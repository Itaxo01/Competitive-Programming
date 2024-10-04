#include <bits/stdc++.h>
using namespace std;

int main(){
	while(true){
		int a, b; cin>>a>>b;
		if(a==0 && b==0) break;
		bitset<1000000001> *bs;
		bs = (bitset<1000000001> *)malloc(sizeof(bitset<1000000001>));
		bs->reset();
		for(int i = 0; i<a; i++){
			int c; cin>>c;
			bs->set(c);
		}
		int count = a+b;
		for(int i = 0; i<b; i++){
			int c; cin>>c;
			if(bs->test(c)) count-=2;
		}
		cout<<count<<endl;
	}
}