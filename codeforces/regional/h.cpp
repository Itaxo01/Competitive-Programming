#include <bits/stdc++.h>
#define ll long long
using namespace std;

void possibles(string m, deque<string> &s, int ind){
	while(m[ind]!='*' and ind<m.size()) ind++;
	
	if(ind == m.size()) return s.push_back(m);
	
	m[ind] = '1';
	possibles(m, s, ind+1);
	m[ind] = '0';
	possibles(m, s, ind+1);
}

ll fastPow(ll x, ll n, ll mod){
	ll res = 1;
	while(n>0){
		if(n & 1) res = (res*x)%mod;
		x = (x*x)%mod;
		n >>= 1;
	} return res;
}

int bitInt(string &s){
	int n = 0;
	for(int i = 0; i<s.size(); i++){
		if(s[i]=='1') n+= (1 << (s.size()-1-i));
	}
	return n;
}

void modAll(deque<string> &s_m, deque<int> &nums){
	for(auto mod:nums){
		for(auto m: s_m){
			int n = 0;
			for(int i = 0; i<m.size(); i++){
				if(m[i]=='1') n = (n+fastPow(2, m.size()-1-i, mod))%mod;
			}
			if(n == 0){
				cout<<m<<endl;
				return;
			}
		}
	}
}

void calculate(string m, string n){
	deque<string> s_m, s_n;
	possibles(m, s_m, 0);
	possibles(n, s_n, 0);
	deque<int> nums(s_n.size());
	for(int i = 0; i<s_n.size(); i++){
		nums[i] = (bitInt(s_n[i]));
	}
	modAll(s_m, nums);

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string m; cin>>m;
	string n; cin>>n;
	calculate(m, n);


	return 0;
}