#include <bits/stdc++.h>


using namespace std;
int main(){
	while(true){
		int n; cin>>n;
		if(n==0) break;
		map<set<int>, int> m;
		int maior = 1;
		for(int i = 0; i<n; i++){
			set<int> s;
			for(int j = 0; j<5; j++){
				int a; cin>>a;
				s.insert(a);
			}
			if(m.find(s)!=m.end()){
				m[s]++;
				if(m[s]>maior) maior = m[s];
			}
			else m[s] = 1;
		}
		int total = 0;
		for(auto e:m){
			if(e.second==maior) total+=maior;
		}
		cout<<total<<endl;
	}
}