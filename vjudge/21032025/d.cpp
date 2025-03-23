#include <bits/stdc++.h>
#define int long long
#define md 1000000007
using namespace std;

vector<int> primes;
bitset<1000000> bs;

void sieve(){
	bs.set();
	for(int i = 2; i*i < 1000000; i++){
		if(bs[i]) primes.push_back(i);
		for(int p = i*i; p < 1000000; p+=i){
			bs.reset(p);
		}
	}
}

void factors(int b, vector<int> &num_factors){
	if(b == 1) return;
	for(int e: primes){
		if(b % e == 0){
			num_factors.push_back(e);
			do {
				b /= e;
			}while(b && b%e == 0);
		}
		if(b == 0) break;
	}
	if(b > 1) {
		num_factors.push_back(b);
	}
}

int pow_mod(int a, int n){
	int res = 1;
	while(n){
		if(n & 1){
			res = (res*a)%md;
		}
		a = (a*a)%md;
		n >>=1;
	}
	return res;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//cout.tie(0);
	sieve();
	int a; cin>>a;
	unordered_map<int, unordered_map<int, int>> conflict;
	// Vou mapear os conflitos entre os primos, caso um numero possua os
	// fatores 2 * 3 * 7, vou mapear todo mundo com todo mundo, isto é
	// m[2][3]++, m[2][7]++, m[3][2]++, m[3][7]++ etc... Como um número até 10^6 possui
	// no máximo 7 fatores primos distintos, a complexidade será 7*7*10^5, o que é viável

	// Além disso, vou obviamente salvar a quantidade de números da entrada que
	// possuem cada determinado primo. Dessa forma, eu irei considerar estes, e
	// depois irei subtrair cada conflito (da forma que eu fiz, os conflitos estão
	// duplicados).
	unordered_map<int, int> prime_count;
	for(int i= 0; i<a; i++){
		int b; cin>>b;
		vector<int> num_factors;
		factors(b, num_factors);
		for(int j = 0; j<num_factors.size(); j++){
			prime_count[num_factors[j]]++;
			for(int k = j+1; k<num_factors.size(); k++){
				conflict[num_factors[j]][num_factors[k]]++;
			}
		}
	}
	int q; cin>>q;
	for(int i = 0; i<q; i++){
		int b; cin>>b;
		vector<int> num_factors;
		factors(b, num_factors);
		int sum = 0;
		for(int e: num_factors){
			sum += prime_count[e];
		}
		for(int j = 0; j<num_factors.size(); j++){
			for(int k = j+1; k<num_factors.size(); k++){
				sum -= conflict[num_factors[j]][num_factors[k]];
			}
		}
		int res = pow_mod(2, a - sum);
		cout<<res<<endl;
	}
}