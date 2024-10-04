#include <bits/stdc++.h>

using namespace std;
int A, B, C;

double dist(pair<double, double> p1, pair<double, double> p2){
	return sqrt(pow(p1.first-p2.first, 2)+pow(p1.second-p2.second, 2));
}

double allDistance(vector<pair<double, double>> &pq, pair<double, double> point){
	double total = 0;
	for(auto e:pq){
		total+=dist(e, point);
	}
	return total;
}

double f(double x){
	return (-A*x-C)/(double)B;
}

int main(){
	int n; cin>>n;
	while(n--){
		int a; cin>>a;
		cin>>A>>B>>C;
		vector<pair<double, double>> pq(a);
		for(int i = 0; i<a; i++){
			cin>>pq[i].first>>pq[i].second;
		}
		double l = -5000.0;
		double r = 5000.0;
		double tol = 1e-9;
		
		while((r-l)>tol){
			double x1 = (2*l+r)/3;
			double y1 = f(x1);
			double x2 = (l+2*r)/3;
			double y2 = f(x2);
			pair<double, double> p1 = {x1, y1};
			pair<double, double> p2 = {x2, y2};
			double d1 = allDistance(pq, p1);
			double d2 = allDistance(pq, p2);
			if(d1<d2){
				r = x2;
			}else if(d2<d1){
				l = x1;
			}else{
				l = x1;
				r = x2;
			}
		}
		double f_r = f(r);

		cout<<fixed<<setprecision(6)<<allDistance(pq, {r, f_r})<<endl;

	}
}