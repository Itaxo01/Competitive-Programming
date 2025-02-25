#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
using namespace std;

int combination(int a, int b){
	int sum = 1;
	for(int i = 1; i <= b; i++){
		sum = sum * (a - b + i) / i;
	}
	return sum;
}

void work(){
    int a; cin>>a;
	string s; cin>>s;
	int b = 0, c = 0;

	for(int i = 0; i<a; i++){
		if(s[i] == '-') b++;
		else c++;
	}
	
	int count = pow(b/2, 2)*c;
	if(b & 1){
		count += (b/2) * c;
	}
	
	cout<<count<<endl;

}


signed main(){
    int tt; cin>>tt;
    while(tt--)
        work();

    return 0;
}