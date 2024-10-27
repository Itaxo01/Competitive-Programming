#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int md = 1000000007;

ll mod(ll a, ll b){
	return ((a%b)+b)%b;
}

ll pisano(ll m){
	long prev = 0;
    long curr = 1;
    long res = 0;
	int count = 0;
	int pos = 0;

    for(int i = 0; i < m * m; i++) {
        long temp = 0;
        temp = curr;
        curr = (prev + curr) % m;
        prev = temp;
		if(curr == 0) return i+2;
        if (prev == 0 && curr == 1){
            res = i + 1;
		}
		
    }
    return pos;
}

void work(){
	ll a, b; cin>>a>>b;
	if(b == 1) cout<<(a%md)<<endl;
	else{
		ll pis = pisano(b);
		// cout<<pis<<endl;
		cout<<mod(mod(a, md)*pis, md)<<endl;		
		// cout<<res<<endl;
	}
}

int main(){
	int n; cin>>n; 
	while(n--) work();
    return 0;
}
