#include <bits/stdc++.h>

using namespace std;


bool resposta = true;

void insert_(int t1, int t2, int b, stack<int> &s, set<int> &nums){
	nums.insert(t2);
	if(!s.empty()){
		while(s.top()<=t1){
			nums.erase(s.top());
			s.pop();
			if(s.empty()) break;
		}
	}
	if(*nums.begin()<t2) resposta = false;
	if(s.size()<b){
		s.push(t2);
	}else{
		resposta = false;
	}

}

int main(){
	while(true){
		int a, b; cin>>a>>b;
		if(!a and !b) break;
		resposta = true;
		stack<int> s;
		set<int> nums;
		for(int i = 0; i<a; i++){
			int t1, t2; cin>>t1>>t2;
			if(t2<t1) resposta = false;
			insert_(t1, t2, b, s, nums);
		}
		int anterior = 0;
		while(!s.empty()){
			if(s.top()<anterior) resposta = false;
			anterior = s.top();
			s.pop();
		}

		if(resposta) cout<<"Sim"<<endl;
		else cout<<"Nao"<<endl;
    }
}