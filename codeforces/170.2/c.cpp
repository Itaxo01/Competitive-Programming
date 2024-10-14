#include <bits/stdc++.h>

using namespace std;
int main(){
	int n; cin>>n;
	while(n--){
		int a, b; cin>>a>>b;
		map<int, int> m;
		for(int i = 0; i<a; i++){
			int c; cin>>c;
			m[c]++;
		}
		int maior = 0;
		int k = 0;
		int count = 0;
		auto last = m.begin();
		for(auto it = m.begin(); it!=m.end(); it = next(it)){
			if(it!=m.begin()){
				if((*prev(it)).first+1 != (*it).first){
					k = 0;
					count = 0;
					last = it;
				}
			}
			if(k < b){
				count+=m[(*it).first];
				k++;
			}else {
				count -= m[(*last).first];
				last = next(last);
				count += m[(*it).first];
			}
			maior = max(count, maior);
		}
		cout<<maior<<endl;
	}
}