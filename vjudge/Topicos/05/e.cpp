#include <bits/stdc++.h>

using namespace std;


int main(){
	bool first = true;
	while(true){
		int n; cin>>n;
		if(!n) break;
		if(!first) cout<<endl;
		first = false;
		deque<int> v(n);
		map<int, int> m;
		int maior = 0;
		for(int i = 0; i<n; i++){
			cin>>v[i];
			v[i] = v[i];
			if(m.find(v[i]) == m.end()) m[v[i]] = 1;
			else m[v[i]]++;
			if(m[v[i]] > maior) maior = m[v[i]];
		}
		cout<<maior<<endl;
		sort(v.begin(), v.end());
		vector<vector<int>> groups(maior);
		
		int i = 0;
		while(!v.empty()){
			int j = 0;
			if(!groups[i].empty()){
				while(groups[i].back()>v[j]) j++;
			}
			groups[i].push_back(v[j]);
			v.erase(v.begin()+j);
			i = (i+1)%maior;
		}
		for(int i = 0; i<groups.size(); i++){
			for(int j = 0; j<groups[i].size(); j++){
				if(j) cout<<" ";
				cout<<groups[i][j];
			}
			cout<<endl;
		}
	}
}