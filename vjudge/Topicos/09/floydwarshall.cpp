#include <bits/stdc++.h>
#define inf 1000000000
using namespace std;

void floydwarshall(vector<vector<int>> &v){
	for(int k = 0; k<v.size(); k++)
		for(int i = 0; i<v.size(); i++)
			for(int j = 0; j<v.size(); j++)
				v[i][j] = min(v[i][j], v[i][k]+v[k][j]);			
}

int main(){
	
}