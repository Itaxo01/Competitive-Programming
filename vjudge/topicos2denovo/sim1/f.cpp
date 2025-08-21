#include <bits/stdc++.h>
using namespace std;


int main(){
	int v0, v1, v2, v3, n; cin>>v0>>v1>>v2>>v3>>n;
	int total = v0+v1+v2+v3+n;
	// a maioria dos votos é (total+1)/2;
	int m = total/2;
	vector<bool> winners(4, false);
	vector<string> aux = {"Donatello", "Leonardo", "Michelangelo", "Rafael"};
	if(v0+n > m || ((total & 1) && v0+n == m+1)) winners[3] = true;
	if(v1+n > m || ((total & 1) && v1+n == m+1)) winners[1] = true;
	if(v2+n > m || ((total & 1) && v2+n == m+1)) winners[0] = true;
	if(v3+n > m || ((total & 1) && v3+n == m+1)) winners[2] = true;

	if(count(winners.begin(), winners.end(), true)){
		for(int i = 0; i<4; i++){
			if(winners[i]) cout<<aux[i]<<endl;
		}
	} else cout<<"sem vencedores"<<endl;


}