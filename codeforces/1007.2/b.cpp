#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>> 
using namespace std;




bool is_sqr(long long x){
    long long r = (long long) sqrt(x);
    return r*r == x;
}


bool is_correct(vector<int> &v){
	int sum = 0;
	for(int i = 0; i<v.size(); i++){
		sum+= v[i];
		if(is_sqr(sum)) return false;
	}
	return true;
}

void work(){
	int a; cin>>a;
	vector<int> v(a);
	for(int i = 0; i<a; i++){
		v[i] = i+1; 
	}
	
	for(int i = 1; i<=a; i++){
		if(is_sqr((1+i)*i/2) && i < a) swap(v[i-1], v[i]);
	}

	// for(int i = 0; i < a; i++){
	// 	int s = 0;
	// 	for(int j = 0; j <= i; j++){
	// 		s += v[j];
	// 	}
	// 	if(is_sqr(s) && i+1 < a){
	// 		swap(v[i], v[i+1]);
	// 	}
	// }
	
	if(is_correct(v)){
		for(int i = 0; i<a; i++){
			if(i) cout<<" ";
			cout<<v[i];
		} cout<<endl;
	} else cout<<"-1\n";

}


signed main(){
	int tt; cin>>tt;
	while(tt--)
		work();
	return 0;
}