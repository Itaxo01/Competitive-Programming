#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> prefix_function(string &s) {
	int n = (int)s.length();
	vector<int> pi(n);
	for (int i = 1; i < n; i++) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}

int mod(int a, int b){
	return (((a%b)+b)%b);
}
int kmp(string &t, string &p){
	vector<int> lps = prefix_function(t);
	int i = 0;
	int j = 0;
	int pos = -1;
	while (i < t.size()) {
		if (t[i] == p[j]) {
			i++;
			j++;
			if (j == p.size()) {
				pos = i-j;
				j = lps[j-1];
				break;
			}
		} else {
			if (j != 0) {
				j = lps[j-1];
			} else {
				i++;
			}
		}
	}
	return pos;
}

signed main(){
	string s; cin>>s;
	int tt; cin>>tt;
	int n = s.size();
	vector<int> pi = prefix_function(s);
	int period = n - pi[n-1];
	if(n%period == 0){
		n = period;
		s = s.substr(0, period);
	}
	int sum = 0;
	bool inverted = false;
	
	vector<int> v(n, 0);

	string s_inverted = s;
	reverse(s_inverted.begin(), s_inverted.end());
	string aux = s+s;
	int pos = kmp(aux, s_inverted);	
	
	int res = 0;
	v[0]++;
	vector<int> invertidos(n);
	for(int i = 0; i<tt; i++){
		char c; cin>>c;
		if(c != 'I'){
			int b; cin>>b;
			if(c == 'R') sum = mod((sum+b), n);
			else sum = mod((sum-b), n);
		} else {
			sum = mod(-sum, n);
			inverted = !inverted;
		}
		
		if(!inverted){
			res += v[sum];
			v[sum]++;
		} else{
			if(pos != -1){
				res += v[mod(-sum+pos, n)];
				v[mod(-sum+pos, n)]++;
			} else {
				res += invertidos[sum];
				invertidos[sum]++;
				
			}
		}
	}
	cout<<res<<endl;
}