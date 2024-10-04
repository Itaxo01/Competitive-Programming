#include <bits/stdc++.h>

using namespace std;

string all = "0123456789";
vector<string> combinations;

void combine(string s){
	if(s.size()==5){
		combinations.push_back(s);
		return;
	}
	for(char e:all){
		if(s.find(e)==-1){
			s+=e;
			combine(s);
			s.pop_back();
		}
	}
}

bool solution(string a, string b){
	set<char> b_letters;
	if(b.size()<4 || b.size()>5) return false;
	if(b.size()==4){
		if(a[0]=='0') return false;
		for(char e:b){
			if(b_letters.find(e)!=b_letters.end()) return false;
			b_letters.insert(e);
			if(e=='0') return false;
			else if(a.find(e)!=-1) return false;

		}
	}
	if(b.size()==5){
		for(char e:b){
			if(b_letters.find(e)!=b_letters.end()) return false;
			b_letters.insert(e);
			if(a.find(e)!=-1) return false;
		}
	}
	return true;
}

int main(){
	bool first = true;
	combine("");
	while(true){
		int n; cin>>n;
		if(!n) break;
		if(!first) cout<<endl;
		vector<pair<string, string>> sol;
		for(auto denum:combinations){
			int denum_int = stoi(denum);
			if(denum_int && denum_int*n<=98765){
				int num = denum_int*n;
				string num_ = to_string(num);
				if(solution(denum, num_)) sol.push_back({num_, denum});
			}
		}
		if(sol.empty()) cout<<"There are no solutions for "<<n<<"."<<endl;
		else{
			for(auto e:sol){
				if(e.first.size()==4){
					cout<<"0"<<e.first<<" / "<<e.second<<" = "<<n<<endl;
				}else{
					cout<<e.first<<" / "<<e.second<<" = "<<n<<endl;
				}
			}
		}

		first = false;
	}
}