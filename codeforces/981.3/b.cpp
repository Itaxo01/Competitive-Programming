#include <bits/stdc++.h>
#define ll long long

using namespace std;

void work(){
	int a; cin>>a;
	int diagonais[2*a-1];
	memset(diagonais, 0, sizeof(diagonais));
	int sum = 0;
	for(int i = 0; i<a; i++){
		for(int j = 0; j<a; j++){
			int c; cin>>c;
			if(c<0){
				diagonais[(a-1)+(i-j)] = min(diagonais[(a-1)+(i-j)], c);
			}
		}
	}
	for(int i = 0; i<2*a-1; i++){
		sum+=diagonais[i];
	}
	cout<<abs(sum)<<endl;
}

int main(){
	int n; cin>>n;
	while(n--){
		work();
	}
}