#include <bits/stdc++.h>
using namespace std;

void expand(string a, int pos, vector<string> &v){
	if(pos == a.size()){
		v.push_back(a);
		return;
	}
	while(pos<a.size() && a[pos]!='*') pos++;
	if(pos == a.size()){
		v.push_back(a);
		return;
	}
	a[pos] = '1';
	expand(a, pos+1, v);
	a[pos] = '0';
	expand(a, pos+1, v);
}

int num(string &a){
	int b = 0;
	int factor = 1;
	for(int i = a.size()-1; i>=0; i--){
		if(a[i] == '1') b+=factor;
		factor*=2;
	}
	return b;
}

bool mod(string &s, int a){
	int factor = 1;
	int sum = 0;
	for(int i = s.size()-1; i>=0; i--){
		if(s[i] == '1'){
			sum = (factor+sum)%a;
		}
		factor = (factor*2)%a;
	}
	if(sum == 0) return true;
	return false;
}

void solve(vector<string> &v, vector<int> &n){
	for(string s: v){
		for(int e:n){
			if(mod(s, e)){
				cout<<s<<endl;
				return;
			}
		}
	}
}

int main(){
	string a, b; cin>>a>>b;
	vector<string> v1;
	bool vb1 = false, vb2 = false;
	for(char e: a){
		if(e == '*'){
			expand(a, 0, v1);
			vb1 = true;
			break;
		}
	}
	vector<string> v2;
	for(char e: b){
		if(e== '*'){
			expand(b, 0, v2);
			vb2 = true;
			break;
		}
	}
	if(!vb1) v1.push_back(a);
	if(!vb2) v2.push_back(b);

	vector<int> n;
	for(string s: v2){
		n.push_back(num(s));
	}
	solve(v1, n);

	// for(int e: n) cout<<e<<" ";
	// cout<<endl;
	// for(string e:v1) cout<<e<<" ";
	// cout<<endl;
}