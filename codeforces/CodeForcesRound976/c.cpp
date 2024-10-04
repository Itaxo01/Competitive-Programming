#include <bits/stdc++.h>

using namespace std;

int main(){
	int b = 13;
	int c = 4;
	for(int a = 0; a<23; a++){
		cout<<((b & ~a) | (a&~c) | (b&~c))<<endl;
	}
}