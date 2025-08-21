#include<bits/stdc++.h>
using namespace std;


int main(){
	int tt; cin>>tt;
	while(tt--){
		int n, k, d, w; cin>>n>>k>>d>>w;
		vector<int> v(n);
		for(auto &a: v) cin>>a;
		// o ideal seria agrupar em grupos de tamanho k, de forma que a diferença de tempo entre o primeiro e o ultimo do grupo seja menor igual a d.
		// vou usar dois ponteiros para ir juntando as pessoas. É garantido que se posso juntar o primeiro e o ultimo, também poderei juntar todos que estão entre eles

		int min_k = 0;

		int i = 0;
		int last = 0;
		while(i < n){
			min_k++;
			while(i < n && i-last+1 <= k  && v[i]-v[last] <= d+w) i++;
			// cout<<last<<" "<<i<<endl;
			if(i == n){
				break;
			} else {
				last = i;
			}
		}
		cout<<min_k<<endl;

	}
}