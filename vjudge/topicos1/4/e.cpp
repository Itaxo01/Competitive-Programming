#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a, int b){
	while(b>0){
		a %= b;
		if(a == 0) return b;
		b %= a;
	}
	return a;
}

struct frac{
	int num, denum;
	frac(int n, int d): num(n), denum(d) {}

	bool operator < (const frac &b) const{
		return (num * b.denum) < (b.num * denum);
	}
};

frac dist(vector<int> &v){
	vector<int> m(v.size());
	frac maior(0, 1);
	int c = -1;
	for(int i = 0; i<v.size(); i++){
		while(c>=0 && v[m[c]] < v[i]){
			c--;
		} 
		if(c >= 0){
			int l = m[c] + 1;
			int e = i-l;
			int ne = v[i]-v[l];
			int de = v[l-1] - v[l];
			int k = gcd(ne, de);
			ne/=k, de/=k;
			
			frac f(e*de+ne, de);
			maior = max(f, maior);
		}
		c++;
		m[c] = i;
	}
	return maior;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	vector<int> v(n);
	vector<int> v2(n);
	for(int i = 0; i<n; i++){
		cin>>v[i];
		v2[n-i-1] = v[i];
	}

	frac maior = max(dist(v2), dist(v));
	
	if(maior.num == 0) cout<<0;
	else if(maior.denum == 1) cout<<maior.num;
	else cout<<maior.num<<"/"<<maior.denum;
	cout<<endl;
}