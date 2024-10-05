#include <bits/stdc++.h>

using namespace std;

int main(){
	int c = 1;
	while(true){
		int a, b; cin>>a>>b;
		if(!a && !b) break;
		deque<int> bac(a);
		deque<int> spn(b);
		for(int i = 0; i<a; i++){
			cin>>bac[i];
		}
		for(int i = 0; i<b; i++){
			cin>>spn[i];
		}
		sort(bac.begin(), bac.end(), greater<int>());
		sort(spn.begin(), spn.end(), greater<int>());

		while(bac.size() > 0 && spn.size() > 0){
			int i = 0;
			int anterior = abs(bac[0]-spn[0]);
			while(i+1<spn.size() && abs(bac[0]-spn[i+1])<anterior){
				anterior = abs(bac[0]-spn[i]);
				i++;
			}
			bac.pop_front();
			spn.erase(spn.begin()+i);
		}
		printf("Case %d: ", c++);
		cout<<bac.size();
		if(!bac.empty()) cout<<" "<<bac[bac.size()-1];
		cout<<endl;
	}
}