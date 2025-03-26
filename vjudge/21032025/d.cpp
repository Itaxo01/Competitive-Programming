#include <bits/stdc++.h>
#define int long long
#define md 1000000007
using namespace std;

vector<int> primes;
bitset<1000006> bs;
vector<vector<int>> fatores(1000005);
vector<int> pot2(100001);
void sieve(){
	bs.set();
	for(int i = 2; i*i <= 1000005; i++){
		if(bs[i]){
			primes.push_back(i);
			fatores[i].push_back(i);
		} else continue;
		for(int p = i*2; p <= 1000005; p+=i){
			bs.reset(p);
			fatores[p].push_back(i);
		}
	}
	for(int i = 1000; i<1000005; i++){
		if(bs[i]){
			fatores[i].push_back(i);
			for(int p = i*2; p <= 1000005; p+=i){
				bs.reset(p);
				fatores[p].push_back(i);
			}
		}
	}
}

// void factors(int b, vector<int> &num_factors){
// 	if(b == 1) return;
// 	for(int e: primes){
// 		if(b % e == 0){
// 			num_factors.push_back(e);
// 			do {
// 				b /= e;
// 			}while(b && b%e == 0);
// 		}
// 		if(b == 0) break;
// 	}
// 	if(b > 1) {
// 		num_factors.push_back(b);
// 	}
// }

// int mult_mod(int a, int b){
// 	int res = 0;
// 	while(b){
// 		if(b & 1){
// 			res = (res+a)%md;
// 		}
// 		a = (a+a)%md;
// 		b >>= 1;
// 	}
// 	return res;
// }

// int pow_mod(int a, int b){
// 	int res = 1;
// 	while(b){
// 		if(b & 1){
// 			res = (mult_mod(a, b))%md;
// 		}
// 		a = (mult_mod(a, a))%md;
// 		b >>=1;
// 	}
// 	return res;
// }

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//cout.tie(0);
	sieve();
	pot2[0] = 1;
	for(int i = 1; i<100001; i++){
		pot2[i] = (pot2[i-1]*2)%md;
	}

	// for(int i = 0; i<100; i++){
	// 	cout<<i<<":";
	// 	for(int e: fatores[i]) cout<<" "<<e;
	// 	cout<<endl;
	// }
	int a; cin>>a;
	vector<int> m(1000001, 0);
	for(int i= 0; i<a; i++){
		int b; cin>>b;
		int n = fatores[b].size();

		for(int i = 1; i<(1<<n); i++){
			int res = 1;
			for(int j = 0; j<n; j++){
				if(i & (1<<j)) res*= fatores[b][j];
			}
			m[res]++;
		}
	}
	int q; cin>>q;
	for(int i = 0; i<q; i++){
		int b; cin>>b;
		int sum = 0;
		int n = fatores[b].size();
		for(int i = 1; i<(1<<n); i++){
			int res = 1;
			int count = 0;
			for(int j = 0; j<n; j++){
				if(i & (1<<j)) {
					res*=fatores[b][j];
					count++;
				}
			}
			if(count & 1){
				sum += m[res];
			} else {
				sum -= m[res];
			}
		}
		int res = pot2[a - sum];
		cout<<res<<endl;
	}
}