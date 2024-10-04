#include <bits/stdc++.h>


using namespace std;

int main(){
	int n; cin>>n;
	while(n--){
		int a, b, c;
		cin>>a>>b>>c;
		set<int> professores;
		for(int i = 0; i<b; i++){
			int pr; cin>>pr;
			professores.insert(pr);
		}

		for(int i = 0; i<c; i++){
			int d; cin>>d;
			auto it = professores.lower_bound(d);
			if(it == professores.end()){
				it--;
				cout<<a-*it<<endl;
			}else if(it == professores.begin()){
				cout<<*it-1<<endl;
			}else{
				auto it2 = it;
				it2--;
				cout<<(*it-*it2)/2<<endl;
			}
		
			
		}
	}
}