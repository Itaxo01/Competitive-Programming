#include <bits/stdc++.h>
using namespace std;

int main(){
	int count = 1;
	while(true){
		int z, i, m, l;
		cin>>z>>i>>m>>l;
		if(!z && !i && !m && !l) break;
		map<int, int> mem;
		int res = m;
		for(int j = 0; j<=m; j++){
			if(mem.find(l) != mem.end()){
				res = j - mem[l];
				break;
			}
			mem[l] = j;
			l = (z*l + i) % m;
		}


		printf("Case %d: %d\n", count++, res);
	}
}