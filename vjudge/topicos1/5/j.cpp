#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define pi 3.14159265358979323846

const ld mult = pi/180;
int main(){
	cin.tie(0); ios_base::sync_with_stdio(0);

	int angle, n; cin>>angle>>n;
	long double res = 0;
	ld t = tan(angle*mult);
	vector<pair<ld, ld>> v(n);
	for(int i = 0; i<n; i++){
		int x, h; cin>>x>>h;
		ld p = h/t;
		v[i] = {x, x+p};
	}
	sort(v.begin(), v.end());
	int pos = 0;
	int next = 1;
	while(pos < v.size()){
		ld add = v[pos].second - v[pos].first;
		while(next < v.size() && v[next].second <= v[pos].second)
			next++;
		if(next < v.size() && v[pos].second > v[next].first){
			add = add - (v[pos].second - v[next].first);
		}
		res += add;
		pos = next;
		next = pos+1;
	}

	printf("%.15Lf\n", res);
}