#include <bits/stdc++.h>

using namespace std;

bool win(vector<int> &pos){
	for(int i = 0; i<8; i++){
		for(int j = 0; j<8; j++){
			if(i!=j){
				if(pos[i]==pos[j]) return false;
				if(abs(i-j)==abs(pos[i]-pos[j])) return false;
			}
		}
	}
	return true;
}

void computate(vector<vector<int>> &wins){
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
	if(win(v)) wins.push_back(v);
	while(next_permutation(v.begin(), v.end())){
		if(win(v)) wins.push_back(v);
	}
}

int main(){
	int a;
	int c = 1;
	vector<int> arr(8);
	vector<vector<int>> allWins;
	computate(allWins);
	while(cin>>a){
		arr[0] = a;
		for(int i = 1; i<8; i++){
			cin>>arr[i];
		}
		int menor = INT_MAX;
		for(auto e:allWins){
			int dif = 0;
			for(int i = 0; i<8; i++){
				if(e[i]!=arr[i]) dif++;
			}
			if(dif<menor) menor = dif;
		}
		printf("Case %d: ", c++);
		cout<<menor<<endl;
	}
}