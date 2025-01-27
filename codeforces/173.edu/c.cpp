#include <bits/stdc++.h>
#define int long long
using namespace std;

int kedane_max(vector<int> &v){
	int res = 0;
	int sum = 0;
	for(int i = 0; i<v.size(); i++){
		sum = max(sum+v[i], v[i]);
		res = max(res, sum);
	}
	return res;
}

int kedane_min(vector<int> &v){
	int res = 0;
	int sum = 0;
	for(int i = 0; i<v.size(); i++){
		sum = min(sum+v[i], v[i]);
		res = min(res, sum);
	}
	return res;
}

pair<int, int> include_left(vector<int> &v, int pos){
	int sum = v[pos];
	int res1 = sum;
	int res2 = sum;
	for(int i = pos-1; i>=0; i--){
		sum += v[i];
		res1 = min(res1, sum);
		res2 = max(res2, sum);
	}
	return {res1, res2};
}
pair<int, int> include_right(vector<int> &v, int pos){
	int sum = v[pos];
	int res1 = sum;
	int res2 = sum;
	for(int i = pos+1; i<v.size(); i++){
		sum += v[i];
		res1 = min(res1, sum);
		res2 = max(res2, sum);
	}
	return {res1, res2};
}

void work(){
	int a; cin>>a;
	map<int, int> m;
	int sum = 0;
	int x_pos = -1;
	int x = 0;
	vector<int> v(a);
	for(int i = 0; i<a; i++){
		int b; cin>>b;
		if(b != 1 && b != -1){
			x = b;
			x_pos = i;
		} 
		v[i] = b;
	}
	if(x_pos == -1){
		int l = kedane_min(v);
		int r = kedane_max(v);
		for(int i = l; i<=r; i++) m[i]++;
		for(int i = l+x; i<=r+x; i++) m[i]++;
	} else{
		int ll, lr, rl, rr;
		vector<int> vl = (vector<int>(v.begin(), v.begin()+x_pos));
		vector<int> vr = (vector<int>(v.begin()+x_pos+1, v.end()));
		ll = kedane_min(vl);
		lr = kedane_max(vl);
		rl = kedane_min(vr);
		rr = kedane_max(vr);
		for(int i = ll; i<=lr; i++) m[i]++;
		for(int i = rl; i<=rr; i++) m[i]++;
		pair<int, int> left = include_left(v, x_pos);
		pair<int, int> right = include_right(v, x_pos);
		int l = left.first + right.first - x;
		int r = left.second + right.second - x;
		for(int i = l; i<=r; i++) m[i]++;
	}




	cout<<m.size()<<endl;
	bool first = true;
	for(auto e: m){
		if(first){
			first = false;
			cout<<e.first;
		}
		else cout<<" "<<e.first;
	}
	cout<<endl;
}

signed main(){
	int tt; cin>>tt;
	while(tt--){
		work();
	}
}