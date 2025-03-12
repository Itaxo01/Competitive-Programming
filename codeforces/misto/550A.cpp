#include <bits/stdc++.h>
using namespace std;
 
bool work(){
	string s; cin>>s;
	vector<int> a, b;
	for(int i = 0; i<s.size()-1; i++){
		if(s[i] == 'A' && s[i+1] == 'B') a.push_back(i);
		else if(s[i] == 'B' && s[i+1] == 'A') b.push_back(i);
	}
	if(a.empty() || b.empty()) return false;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if(abs(a[0]-b[b.size()-1]) > 1 || abs(a[a.size()-1]-b[0]) > 1 ) return true;
	return false;
 
}
 
int main(){
	if(work()) cout<<"YES\n";
	else cout<<"NO\n";
}