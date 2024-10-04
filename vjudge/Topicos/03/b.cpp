#include <bits/stdc++.h>

using namespace std;

bool checkValid(vector<int> v, vector<pair<int, pair<int, int>>> c){
	for(auto e:c){
		int a = e.second.first, b = e.second.second;
		int pos_a=0, pos_b=0;
		for(int i = 0; i<v.size(); i++){
			if(v[i]==a) pos_a = i;
			if(v[i]==b) pos_b = i;
		}
		if(e.first>=0){
			if(abs(pos_a-pos_b)>e.first) return false;
		}else{
			if(abs(pos_a-pos_b)<abs(e.first)) return false;
		}
	}
	return true;
}

int main(){
	while(true){
		int a, b;
		cin>>a>>b;
		if(!a and !b) break;
		vector<int> v;
		for(int i = 0; i<a; i++){
			v.push_back(i);
		}
		vector<pair<int, pair<int, int>>> constrains;
		for(int i = 0; i<b; i++){
			int a_, b_, c_; cin>>a_>>b_>>c_;
			constrains.push_back({c_, {a_, b_}});
		}
		int counter = 0;
		if(checkValid(v, constrains)) counter++;
		while(next_permutation(v.begin(), v.end())){
			if(checkValid(v, constrains)) counter++;
		}
		cout<<counter<<endl;
	}
}