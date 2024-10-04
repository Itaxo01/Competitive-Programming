#include <bits/stdc++.h>

using namespace std;

double NPV(vector<int> cf, double irr){
	int t = cf.size();
	double total = 0;
	double divisor = 1.0;
	for(int i = 0; i<t; i++){
		total+= cf[i]/divisor;
		divisor= min(divisor*(1+irr), 1000000000.0);
	}
	return total;
}

int main(){
	while(1){
		int n; cin>>n;
		if(!n) break;
		vector<int> cf(n+1);
		for(int i = 0; i<=n; i++) cin>>cf[i];
		double l = -1, r = 30;
		while(r-l>1e-9){
			double mid = (l+r)/2;
			if(NPV(cf, mid)<0) r = mid;
			else l = mid;
		}
		cout<<fixed<<setprecision(2)<<l<<endl;
	}
}