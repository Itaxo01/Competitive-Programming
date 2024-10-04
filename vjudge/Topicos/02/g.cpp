#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> v1, vector<int> v2){
	if(v1[1]==v2[1]){
		if(v1[2]==v2[2]){
			return v1[0]<v2[0];
		}else return v1[2]<v2[2];
	}else return v1[1]>v2[1];
}

int main(){
	string s;
	getline(cin, s);
	stringstream ss(s);
	int n;
	ss >> n;
	getline(cin, s);
	for(int i = 0; i<n; i++){
		if(i!=0) cout<<endl;
		map<int, pair<int, int>> team;
		map<int, vector<int>> penality;
		while(getline(cin, s)){
			if(s.size()==1) break;
			stringstream ss(s);
			int a;
			int b, c; 
			char t; ss>>a>>b>>c>>t;
			if(team.find(a)==team.end()){
				team[a] = {0, 0};
				penality[a] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
			}
			if(t == 'I'){
				if(penality[a][b-1]>=0)
					penality[a][b-1] +=20;
			}else if(t == 'C'){
				if(penality[a][b-1]>=0){
					team[a].first++;
					team[a].second += penality[a][b-1]+c;
					penality[a][b-1] = -1;
				}
			}
		}
		vector<vector<int>> result;
		for(auto e:team){
			vector<int> v1 = {e.first, e.second.first, e.second.second};
			result.push_back(v1);
		}
		sort(result.begin(), result.end(), cmp);
		for(auto e:result){
			cout<<e[0]<<" "<<e[1]<<" "<<e[2]<<endl;
		}
	}

}   