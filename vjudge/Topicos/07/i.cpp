#include <bits/stdc++.h>
using namespace std;

int main(){
	int a;
	int count = 1;
	while(cin>>a){
		unordered_map<string, int> sm;
		unordered_map<int, string> ms;

		for(int i = 0; i<a; i++){
			string c; cin>>c;
			sm[c] = i;
			ms[i] = c;
		}
		int b; cin>>b;
		vector<vector<int>> v(a);
		int pesos[a] = {0};

		for(int i = 0; i<b; i++){
			string c, d; cin>>c>>d;
			v[sm[c]].push_back(sm[d]);
			pesos[sm[d]]++;
		}

		priority_queue<int, vector<int>, greater<int>> ready;
		for(int i = 0; i<a; i++){
			if(pesos[i] == 0) ready.push(i);
		}

		printf("Case #%d: Dilbert should drink beverages in this order:", count++);

		while (!ready.empty()) {
			int t = ready.top();
			ready.pop();
			cout<<" "<<ms[t];
			for (int e: v[t]){
				pesos[e]--;
				if(pesos[e] == 0) ready.push(e);
			}
		}

		printf(".\n\n");

		
	}
}