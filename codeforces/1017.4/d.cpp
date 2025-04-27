#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int, int>> count(string &s){
	int is_r = -1;
	int count = 0;
	vector<pair<int, int>> v1;
	for(char e: s){
		if(is_r == -1){
			if(e == 'L'){
				count = 1;
				is_r = 0;
			} else{
				count = 1;
				is_r = 1;
			}
		} else if(is_r == 0){
			if(e == 'L'){
				count++;
			} else{
				v1.push_back({count, is_r});
				is_r = 1;
				count = 1;
			}
		} else {
			if(e == 'L'){
				v1.push_back({count, is_r});
				is_r = 0;
				count = 1;
			} else{
				count++;
			}
		}
	}

	v1.push_back({count, is_r});
	return v1;
}

bool work(){
	string s1, s2;
	cin>>s1>>s2;
	vector<pair<int, int>> v1 = count(s1), v2 = count(s2);
	if(v1.size() != v2.size()) return false;
	for(int i = 0; i<v1.size(); i++){
		if(v2[i].first < v1[i].first || v2[i].first > 2*v1[i].first || v1[i].second != v2[i].second) return false;
	}
	return true;

}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt; cin>>tt;
	while(tt--){
		if(work()){
			cout<<"YES"<<endl;
		} else{
			cout<<"NO"<<endl;
		}
	}
}