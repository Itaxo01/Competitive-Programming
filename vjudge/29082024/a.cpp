#include <bits/stdc++.h>

using namespace std;
long long a, b, c, l, r; 
long long area(long long l, long long r){
	return abs((
		((2*a*(long long)pow(r, 3)))
		+(3*b*(long long)pow(r, 2))
		+(6*c*r))
		-((2*a*(long long)pow(l, 3))
		+(3*b*(long long)pow(l, 2))
		+(6*c*l)));
}

long long gcd(long long a, long long b){
	if(b==0) return a;
	return gcd(b, a%b);
}

int main(){
	long long n; cin>>n;
	for(long long i = 0; i<n; i++){
		cin>>a>>b>>c>>l>>r;
		long long d = (long long)pow(b, 2)-4*a*c;
		set<long long> v;
		v.insert(l);
		if(d>0){
			double delta = sqrt(d);
			long long x1 = (long long)(-b-delta)/(2*a);
			long long x2 = (long long)(-b+delta)/(2*a);
			if(x1>l and x1<r) v.insert(x1);
			if(x2>l and x2<r) v.insert(x2);
		}
		v.insert(r);
		long long num = 0;
		long long anterior = *v.begin();
		for(auto it = ++v.begin(); it != v.end(); it++){
			num+= area(anterior, *it);
			anterior = *it;
		}
		long long gc = gcd(num, 6);
		cout<<num/gc<<"/"<<6/gc<<endl;
		
	}

}