#include <bits/stdc++.h>
#define int long long
using namespace std;

void work(){
	int n, x; cin>>n>>x;
	int res = x;
	if(x == 0){
		if(n % 2 == 0) res += n;
		else if(n == 1) res = -1;
		else {
			if(n > 3){
				res += (n-3);
			}
			res += 6;
		}
	} else {
		int num_b = 0;
		int mex_b = 0;
		vector<int> v;
		for(int i = 0; i<33; i++){
			if(x & ((int)1 << i)){
				if(mex_b == i) mex_b++;
				num_b++;
				v.push_back(i);
			}
		}
		int k = n - num_b; // quantos numeros ainda precisarei preencher
		if(k % 2 != 0 && num_b == 1){
			res += pow(2, mex_b+1);
			k -= 1; 
		} else if (k & 1) k++;
		if(k > 0){
			res += k;
		}
	}
		
	cout<<res<<endl;
	// 27 = 16 + 8 + 2 + 1 = 11011

}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	while(n--){
		work();
	}	
}