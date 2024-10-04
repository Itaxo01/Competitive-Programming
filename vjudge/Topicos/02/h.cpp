#include <bits/stdc++.h>


using namespace std;
int main(){
	while(true){
		int n; cin>>n;
		if(n == 0) break;
		multiset<int> ms;
		long long total = 0;
		for(int i = 0; i < n; i++){
			int a; cin>>a;
			for(int j = 0; j<a; j++){
				int b; cin>>b;
				ms.insert(b);
			}
			auto it = --ms.end();
			total += abs(*ms.begin()-*(it));
			ms.erase(it);
			ms.erase(ms.begin());
		}
		cout<<total<<endl;
	}
}