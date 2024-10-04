#include <bits/stdc++.h>

using namespace std;
int main(){
	double x, y, z; cin>>x>>y>>z; // caixa
	double x1, y1, z1; cin>>x1>>y1>>z1; //maçã teo
	double r1; cin>>r1; //raio teo
	double dx1, dx2, dy1, dy2, dz1, dz2,

	dx1y1, dx1y2, dx2y1, dx2y2,
	dx1z1, dx1z2, dx2z1, dx2z2,
	dy1z1, dy1z2, dy2z1, dy2z2,

	dx1y1z1, dx1y1z2, dx1y2z1, dx1y2z2,
	dx2y1z1, dx2y1z2, dx2y2z1, dx2y2z2;

	//d x, y, z
	dx1 = x1-r1;
	dx2 = x-(x1+r1); 
	dy1 = y1-r1; 
	dy2 = y-(y1+r1);
	dz1 = z1-r1;
	dz2 = z-(z1+r1);
	//4 d xy, xz, yz;
	dx1y1 = sqrt(pow(x1, 2)+pow(y1, 2)) - r1;
	dx1y2 = sqrt(pow(x1, 2) + pow((y-y1), 2)) - r1;
	dx2y1 = sqrt(pow((x-x1), 2) + pow(y1, 2)) - r1;
	dx2y2 = sqrt(pow((x-x1), 2) + pow((y-y1), 2)) - r1;

	dx1z1 = sqrt(pow(x1,2) + pow(z1, 2)) - r1;
	dx1z2 = sqrt(pow(x1,2) + pow((z-z1), 2)) - r1;
	dx2z1 = sqrt(pow((x-x1), 2) + pow(z1, 2)) - r1;
	dx2z2 = sqrt(pow((x-x1), 2) + pow((z-z1), 2)) - r1;
	
	dy1z1 = sqrt(pow(y1, 2) + pow(z1, 2)) - r1;
	dy1z2 = sqrt(pow(y1, 2) + pow((z-z1), 2)) - r1;
	dy2z1 = sqrt(pow((y-y1), 2) + pow(z1, 2)) - r1;
	dy2z2 = sqrt(pow((y-y1), 2) + pow((z-z1), 2)) - r1;

	dx1y1z1 = sqrt(pow(x1, 2)+pow(y1, 2)+pow(z1, 2))-r1;
	dx1y1z2 = sqrt(pow(x1, 2)+pow(y1, 2)+pow((z-z1), 2))-r1;
	dx1y2z1 = sqrt(pow(x1, 2)+pow((y-y1), 2)+pow(z1, 2))-r1;
	dx1y2z2 = sqrt(pow(x1, 2)+pow((y-y1), 2)+pow((z-z1), 2))-r1;
	dx2y1z1 = sqrt(pow((x-x1), 2)+pow(y1, 2)+pow(z1, 2))-r1;
	dx2y1z2 = sqrt(pow((x-x1), 2)+pow(y1, 2)+pow((z-z1), 2))-r1;
	dx2y2z1 = sqrt(pow((x-x1), 2)+pow((y-y1), 2)+pow(z1, 2))-r1;
	dx2y2z2 = sqrt(pow((x-x1), 2)+pow((y-y1), 2)+pow((z-z1), 2))-r1;

	vector<double> s;
	s.push_back(dx1);
	s.push_back(dx2);
	s.push_back(dy1);
	s.push_back(dy2);
	s.push_back(dz1);
	s.push_back(dz2);
	s.push_back(dx1y1/(sqrt(2)));
	s.push_back(dx2y1/(sqrt(2)));
	s.push_back(dx1y2/(sqrt(2)));
	s.push_back(dx2y2/(sqrt(2)));
	s.push_back(dy1z1/(sqrt(2)));
	s.push_back(dy1z2/(sqrt(2)));
	s.push_back(dy2z1/(sqrt(2)));
	s.push_back(dy2z2/(sqrt(2)));
	s.push_back(dx1z1/(sqrt(2)));
	s.push_back(dx1z2/(sqrt(2)));
	s.push_back(dx2z1/(sqrt(2)));
	s.push_back(dx2z2/(sqrt(2)));
	s.push_back(dx1y1z1/(sqrt(3)));
	s.push_back(dx1y1z2/(sqrt(3)));
	s.push_back(dx1y2z1/(sqrt(3)));
	s.push_back(dx1y2z2/(sqrt(3)));
	s.push_back(dx2y1z1/(sqrt(3)));
	s.push_back(dx2y1z2/(sqrt(3)));
	s.push_back(dx2y2z1/(sqrt(3)));
	s.push_back(dx2y2z2/(sqrt(3)));
	sort(s.begin(), s.end());
	printf("%.15f", s[s.size()-1]/2);
	
}