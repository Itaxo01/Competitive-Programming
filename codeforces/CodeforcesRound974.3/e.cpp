#include <bits/stdc++.h>

using namespace std;

bitset<200001> horses;
int gv[200001][200001];

int main(){
	int n; cin>>n;
	while(n--){
		horses.reset();
		memset(gv, {0}, 200001);
		int v, e, h; cin>>v>>e>>h;
		for(int i = 0; i<h; i++){
			int h_; cin>>h_;
			horses.set(h_-1);
		}

		for(int i = 0; i<e; i++){
			int a, b, c; cin>>a>>b>>c;
			gv[a-1][b-1] = c;
			gv[b-1][a-1] = c;
				
		}
	}
}