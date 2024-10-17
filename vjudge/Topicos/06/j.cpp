#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	while(n--){
		int a; cin>>a;
		int M[a][a];
		for(int i = 0; i<a; i++){
			for(int j = 0; j<a; j++){
				cin>>M[i][j];
			}
		}
		int m[3*a][3*a];
		int bi = -1, bj = -1;
		for(int i = 0; i<3*a; i++){
			memset(m[i], 0, 3*a*sizeof(int));
			if(i%a == 0) bi++;
			for(int j = 0; j<3*a; j++){
				if(j%a == 0) bj++;
				if((bi-1)%3 != 0)
					if((bj-1)%3 != 0) continue;
				m[i][j] = M[i%a][j%a];
			}
		}
		for(int i = 0; i<3*a; i++){
			for(int j = 0; j<3*a; j++){
				printf("%2d ", m[i][j]);
			}cout<<endl;
		}
	}
}