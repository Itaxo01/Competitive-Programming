#include <bits/stdc++.h>

using namespace std;
int main(){
	int c = 1;
	int n; cin>>n;
	for(int k = 0; k<n; k++){
		int m; cin>>m;
		map<int, set<int>> total;
		for(int i = 0; i<m; i++){
			int a; cin>>a;
			for(int j = 0; j<a; j++){
				int bd; cin>>bd;
				total[bd].insert(i);
			}
		}
		int soma_total = 0;
		vector<int> player(m, 0);
		for(auto e:total){
			if(e.second.size()==1){
				player[*e.second.begin()]++;
				soma_total++;
			}
		}
		cout<<"Case "<<c<<":"; c++;
		for(int e:player){
			printf(" %.6f%%", 100*(e/(double)soma_total));
		}cout<<endl;
	}
	return 0;
}