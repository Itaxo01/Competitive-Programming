#include <bits/stdc++.h>
using namespace std;

int main(){
	string s; cin>>s;
	unordered_map<int, int> m;
	for(int i = s.size()-1; i>=0; i--){
		char e = s[i];
		if(m.find(e - '0') != m.end()){
			cout<<s.size()-(s.size()-i)+1<<endl;
			break;
		} else m[e - '0'] = i;
	}
}