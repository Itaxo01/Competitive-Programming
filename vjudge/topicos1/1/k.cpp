#include <bits/stdc++.h>
using namespace std;

bool is_vogal(char e){
	return (e == 'A' || e == 'E' || e == 'I' || e == 'O' || e == 'U' || e == 'Y');
}

int main(){
	int a; cin>>a;
	if(a >= 3){
		int count = 0;
		string res = "";
		string s1, s2; cin>>s1>>s2;
		bool ans = true;
		bool qlqcoisa = false;
		for(int i = 2; i<a; i++){
			string s3; cin>>s3;
			if(qlqcoisa){
				count+=2; res+=s1.substr(0, 2); qlqcoisa = false;
			}else{
				if(is_vogal(s1[0]) || is_vogal(s2[0]) || is_vogal(s3[0])){
					count++; res+=s1[0];
				} else if(s2.size() > 1 && is_vogal(s2[1])){
					count++; res+=s1[0];
					qlqcoisa = true;
				} else if(s1.size() > 1 && is_vogal(s1[1])){
					count+=2; res+=s1.substr(0, 2);
				} else if(s1.size() > 2 && is_vogal(s1[2])){
					count+=3; res += s1.substr(0, 3);
				} else {
					ans = false; break;
				}
			}
			s1 = s2;
			s2 = s3;
		}
		if(is_vogal(res.back()) || is_vogal(s1[0]) || is_vogal(s2[0])){
			count += 2;
			res += s1[0];
			res += s2[0];
		} else if(s1.size() > 1){
			count += 3;
			res += s1.substr(0, 2);
			res += s2[0];
		} else {
			count +=2;
			res += s1[0];
			res += s2[0];
		}
		
		int sum = 0;
		int c = 0;
		for(int i = 0; i<a; i++){
			if(c < 3){
				c++;
				sum+= !is_vogal(res[i]);
			} else {
				sum+= !is_vogal(res[i]);
				sum-= !is_vogal(res[i-3]);
				if(sum == 3) ans = false;
			}
		}
		if(sum == 3) ans = false;
		if(!ans) cout<<"*\n";
		else cout<<count<<endl;
		// cout<<res<<endl;
	} else cout<<a<<endl;
}