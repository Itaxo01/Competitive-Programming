#include <bits/stdc++.h>


using namespace std;

void work(){
	string a, b; cin>>a>>b;
	map<char, deque<int>> m;
	for(int i = 0; i<a.size(); i++){
		m[a[i]].push_back(i);
	}

	int i = 0;
	int ult = -1;
	bool res = true;
	string res1 = a;
	for(int i = 0; i<b.size(); i++){
		char t = b[i];
		if(m.find(t) == m.end()){
			if(m['?'].empty()){
				res = false;
				break;
			} else{
				int f = m['?'].front();
				if(f>ult){
					ult = f; m['?'].pop_front();
					res1[f] = t;
				} else {
					res = false;
					break;
				}
			}
		} else{
			if(!m['?'].empty() && m[t].front()> m['?'].front()){
				if(m['?'].front() > ult){
					ult = m['?'].front();
					res1[m['?'].front()] = t;
					m['?'].pop_front();
				} else{
					res = false;
					break;
				}
			} else if(m[t].front()>ult){
				ult = m[t].front();
				m[t].pop_front();
			} else{
				if(m['?'].empty()){
					res = false;
					break;
				} else{
					int f = m['?'].front();
					if(f>ult){
						ult = f; m['?'].pop_front();
						res1[f] = t;
					} else {
						res = false;
						break;
					}
				}
			}
		}
	}
	for(int i = 0; i<res1.size(); i++){
		if(res1[i]=='?') res1[i] = 'a';
	}
	if(res){
		cout<<"YES"<<endl<<res1<<endl;
	} else cout<<"NO"<<endl;
}

int main(){
	int n; cin>>n;
	while(n--){
		work();
	}
}