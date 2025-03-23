#include <bits/stdc++.h>
#define int long long
using namespace std;

void factorize(int a, map<int, int> &factors){
	while(!(a & 1)) {a>>=1; factors[2]++;}
	while(!(a % 3)) {a%=3; factors[3]++;}
	for(int i = 5; i*i<=a; i+=6){
		while(a%i == 0){ factors[i]++; a/=i; }
		while(a%(i+2) == 0){ factors[i+2]++; a/=(i+2);}
	}
	if(a > 1) factors[a]++;
}

void divisors(map<int, int> &factors, set<int> &d){
	d.clear(); d.insert(1);
    for(auto e: factors){
        int p = e.first;
        int exp = e.second;
        vector<int> aux;
        for(auto c : d){
            long long temp = 1;
            for(int i = 0; i < exp; i++){
                temp *= p;
                aux.push_back(c * temp);
            }
        }
        for(auto v : aux) d.insert(v);
    }
}

signed main(){
	int a; cin>>a;
	map<int, int> factors;
	factorize(a, factors);

	bool res = false;
	int sum = 0;
	for(auto e: factors){
		sum+=e.second;
	}
	// cout<<factors.size()<<" "<<sum<<endl;
	if(factors.size() == 1) res = sum & 1;
	else if(sum <= 2 && sum) res = true;
	// set<int> d; divisors(factors, d);
	// for(auto e: d){
	// 	cout<<e<<" ";
	// }cout<<endl;
	
	if(res) cout<<"Y\n";
	else cout<<"N\n";
	
}