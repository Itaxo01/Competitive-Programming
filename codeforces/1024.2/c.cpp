#include <bits/stdc++.h>
#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;


void work(){
	int n; cin>>n;
	// Implementar uma lógica circular, de alguma forma.
	// 	8 1 2
	//  7 0 3
	//  6 5 4
	int count = n * n - 1;
	vector<vector<int>> v(n, vector<int>(n));
    vector<vector<bool>> vis(n, vector<bool>(n, false));

    vector<int> dr = { 0, 1, 0, -1 };
    vector<int> dc = { 1, 0, -1, 0 };
    int r = 0, c = 0;
    int idx = 0;

    for (int i = 0; i < n * n; ++i) {
        v[r][c] = count; count--; 
        vis[r][c] = true;
        int newR = r + dr[idx];
        int newC = c + dc[idx];
        if (0 <= newR && newR < n && 0 <= newC && newC < n
            && !vis[newR][newC]) {
            r = newR;
            c = newC;
        }
        else {
            idx = (idx + 1) % 4;
            r += dr[idx];
            c += dc[idx];
        }
    }
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(j) cout<<" ";
			cout<<v[i][j];
		} cout<<endl;
	}
}

signed main(){
	fastio
	int tt; cin>>tt;
	while(tt--){
		work();
	}
}