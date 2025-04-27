#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	vector<vector<int>> m(n, vector<int>(n));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cin>>m[i][j];
		}
	}

	vector<vector<int>> hungaro((n+1)/2, vector<int>((n+1)/2));
	for(int i = 0; i<(n+1)/2; i++){
		int impar = 2*i + 1;
		for(int j = 0; j<(n+1)/2; j++){
			int p1 = j*2;
			hungaro[i][j] =
		}
	}
}