#include <bits/stdc++.h>
using namespace std;
#define int long long

void factorize(int a, map<int, int> &factors){
  for(int i = 2; i*i<=a; i++){
    while(a%i == 0){
      factors[i]++;
      a/=i;
    }
  }
  if(a > 1) factors[a]++;
}

signed main(){
	int y, k; cin>>y>>k;
	map<int, int> f; factorize(y, f);
	int x = 1;
	auto it = f.begin(), fit = f.end();

	while(k && it != fit){
		int d = min(k, it->first - 1);
		x += x*d;
		k-=d;
		it->second--;
		if(it->second == 0)
			it++;
	}
	x += x*k;


	cout<<x<<endl;
}