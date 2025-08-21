#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	for(int t = 0; t<n; t++){
		vector<vector<char>> v(3, vector<char>(3));
		for(auto &vi: v){
			for(auto &c: vi) cin>>c;
		}
		for(int i = 0; i<3; i++){
			if(v[i][0] != '.' && v[i][0] == v[i][1] && v[i][1] == v[i][2]) {
				cout<<v[i][0]<<endl;
				goto finnaly;
			}
			if(v[0][i] != '.' && v[0][i] == v[1][i] && v[1][i] == v[2][i]) {
				cout<<v[0][i]<<endl;
				goto finnaly;
			}
		}
		if(v[0][0] != '.' && v[0][0] == v[1][1] && v[1][1] == v[2][2]) {
			cout<<v[0][0]<<endl;
			goto finnaly;
		}
		if(v[0][2] != '.' && v[0][2] == v[1][1] && v[1][1] == v[2][0]) {
			cout<<v[0][2]<<endl;
			goto finnaly;
		}

		cout<<"DRAW"<<endl;

		finnaly:
		continue;
	}
}