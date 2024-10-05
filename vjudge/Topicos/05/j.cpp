#include <bits/stdc++.h>

using namespace std;

int remove(int a){
	int acc = 0;
	for(char e: to_string(a)){
		acc+=e-'0';
	}
	return acc;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b; cin>>a>>b;
	priority_queue<int> pq;
	unordered_map<int, int> m;
	for(int i = 0; i<a; i++){
		int c; cin>>c;
		if(m.find(c) == m.end()){ 
			m[c] = 1;
			pq.push(c);
		}
		else m[c]++;
	}
	int i = 0;
	while(i<b-1 && !pq.empty()){
		int c = pq.top();
		int quantia = m[c];
		if(i+quantia>=b) break;
		m.erase(c);
		pq.pop();
		c-=remove(c);
		if(c){
			if(m.find(c) != m.end()) m[c]+=quantia;
			else{
				m[c] = quantia;
				pq.push(c);
			}
		}
		i+=quantia;
	}
	if(pq.empty()){
		cout<<"0"<<endl;
		return 0;
	}
	int c = pq.top();
	cout<<remove(c)<<endl;
}