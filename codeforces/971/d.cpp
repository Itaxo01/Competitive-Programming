#include <bits/stdc++.h>

using namespace std;

pair<int, int> bhaskara(int a, int b, int c){
	int delta = pow(b, 2)-4*a*c;
	if(delta<0) return {-1, -1};
	else if(delta==0){
		double x = -b/(double)(2*a);
		if(x-(int)x!=0) return {-1, -1};
		return {(int)x, -1};
	}else{
		double x1 = (-b+sqrt(delta))/(double)(a*2);
		double x2 = (-b-sqrt(delta))/(double)(a*2);
		if(x1-(int)x1!=0) x1 = -1;
		if(x2-(int)x2!=0) x2 = -1;
		return {x1, x2};
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	for(int i = 0; i<n; i++){
		int a; cin>>a;
		deque<int> v0;
		deque<int> v1;
		bitset<200001> bv0;
		bitset<200001> bv1;
		bv0.reset(); bv1.reset();		
		
		for(int j = 0; j<a; j++){
			int c, d; cin>>c>>d;
			if(d){ v1.push_back(c);
			bv1.set(c);}
			else {v0.push_back(c);
			bv0.set(c);}
		}
		int count = 0;
		for(int i = 0; i<v0.size(); i++){
			int p1 = v0[i];
			for(int j = i+1; j<v0.size(); j++){
				int p2 = v0[j];
				if(bv1.test(p1)) count++;
				if(bv1.test(p2)) count++;
				int x0 = min(p1, p2);
				int x1 = max(p1, p2);
				int a_, b_, c_;
				a_ = 2;
				b_ = (-2*x0)+(-2*x1);
				c_ = 2*x0*x1+2;
				pair<int, int> x = bhaskara(a_, b_, c_);
				if(x.first!=-1) if(bv1.test(x.first)) count++;
				if(x.second!=-1) if(bv1.test(x.second)) count++;
			}
		}

		for(int i = 0; i<v1.size(); i++){
			int p1 = v1[i];
			for(int j = i+1; j<v1.size(); j++){
				int p2 = v1[j];
				if(bv0.test(p1)) count++;
				if(bv0.test(p2)) count++;
				int x0 = min(p1, p2);
				int x1 = max(p1, p2);
				int a_, b_, c_;
				a_ = 2;
				b_ = (-2*x0)+(-2*x1);
				c_ = 2*x0*x1+2;
				pair<int, int> x = bhaskara(a_, b_, c_);
				if(x.first!=-1) if(bv0.test(x.first)) count++;
				if(x.second!=-1) if(bv0.test(x.second)) count++;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
