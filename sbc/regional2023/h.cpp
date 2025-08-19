#include <bits/stdc++.h>
using namespace std;


int main(){
	int n, s; cin>>n>>s;


	for(int i = 0; i<n; i++){
		int l, r, c; cin>>l>>r>>c;
		// primeiramente não faz sentido trabalhos que gerem um custo maior do que o retorno
		if(c >= s*(r-l+1)) continue;
		
	}
}