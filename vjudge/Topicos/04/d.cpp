#include <bits/stdc++.h>

using namespace std;

double f(double x, double p, double q, double r, double s, double t, double u){
	return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main(){

	double p, q, r, s, t, u;
	while(cin>>p>>q>>r>>s>>t>>u){
		double tol = 1e-7;
		double dif = 1;
		double inicio = 0, fim = 1;
		double counter = 0;
		bool sol = true;
		while(dif>tol){
			if(inicio>fim || counter>100){
				cout<<"No solution"<<endl;
				sol = false;
				break;
			}
			counter++;
			double mid = (inicio+fim)/2;
			double fmid = f(mid, p, q, r, s, t, u);
			double finicio = f(inicio, p, q, r, s, t, u);
			dif = abs(fmid);
			if(dif<tol) break;
			if(fmid*finicio>0) inicio = mid;
			else fim = mid;
		}
		if(sol)
			cout<<fixed<<setprecision(4)<<(inicio+fim)/2<<endl;
	}
}