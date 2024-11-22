#include <bits/stdc++.h>
#define ii pair<int, int>
const int INF = 2e9;
using namespace std;

void floydwarshall(vector<vector<int>> &v){
	for(int k = 0; k<v.size(); k++)
		for(int i = 0; i<v.size(); i++)
			for(int j = 0; j<v.size(); j++)
				v[i][j] = min(v[i][j], v[i][k]+v[k][j]);			
}

int main(){
	int a, b; cin>>a>>b;
	vector<vector<int>> v(a, vector<int>(a));
	vector<ii> order;
	for(int i = 0; i<b ; i++){
		int x, y, w; cin>>x>>y>>w;
		v[x-1][y-1] = w;
		v[y-1][x-1] = w;
		order.push_back({x-1, y-1});
	}

}