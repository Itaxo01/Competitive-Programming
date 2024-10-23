#include <bits/stdc++.h>
#define int long long
using namespace std;
string v = "ae";
string c = "bcd";

void work(){
	int a; cin>>a;
	string s; cin>>s;
	string sil = "";
	string res = "";
	bool first = true;
	for(int i = 0; i<a; i++){
		if(v.find(s[i]) != -1){
			sil.push_back(s[i]);
		} else{
			if(sil.size()==0) sil.push_back(s[i]);
			if(sil.size()==2){
				if(i!=a-1){
					if(c.find(s[i+1]) != -1){
						sil.push_back(s[i]);
						if(first){
							first = false;
							res.append(sil);
						} else{
							res.append("."+sil);
						}
						sil = "";
					} else {
						if(first){
							first = false;
							res.append(sil);
						} else{
							res.append("."+sil);
						}
						sil = "";
						sil.push_back(s[i]);
					}
				} else {
					sil.push_back(s[i]);
				}
			}
		}
	}
	if(sil.size()>0){
		if(first){
			first = false;
			res.append(sil);
		} else{
			res.append("."+sil);
		}
	}
	cout<<res<<endl;
}

signed main(){
	int n; cin>>n;
	while(n--){
		work();
	}
}