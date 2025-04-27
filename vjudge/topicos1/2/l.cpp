#include <bits/stdc++.h>
using namespace std;


int main(){
	string s; cin>>s;
	for(int i = 0; i<s.size(); i++){
		if(s[i] > 'a' && s[i] <='z') s[i] = 'a';
		else if(s[i] == '*' || s[i] == '/' || s[i] == '-') s[i] = '+';
	}
	unordered_map<string, int> m;
	m["a("]++;
	m[")a"]++;
	m["++"]++;
	m["+)"]++;
	m["(+"]++;
	m["()"]++;
	m[")("]++;
	vector<string> good_strings;
	int pos = 0;
	for(int i = 0; i<s.size()-1; i++){
		if(m.find(s.substr(i, 2)) != m.end()){
			good_strings.push_back(s.substr(pos, i+1-pos));
			pos = i+1;
		}
	}
	good_strings.push_back(s.substr(pos, s.size()-pos));
	int res = 0;

	for(auto s1: good_strings){
		vector<string> v;
		int i = 0;
		while(i < s1.size()){
			int count = 0; 
			if(s1[i] == 'a'){
				while(i < s1.size() && s1[i] == 'a'){
					count++;
					i++;
				}
				v.push_back(to_string(count));
			} else {
				v.push_back(s1.substr(i, 1));
				i++;
			}
		}
		
	}
}