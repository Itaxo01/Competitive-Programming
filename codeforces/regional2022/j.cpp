#include <bits/stdc++.h>
using namespace std;

int solve(int j, int m, vector<int> &cartas){	
	if(j > m){
		int menor = 24-j;
		if (menor <= 10)
			for(int i = menor-1; i<13; i++){
				if(cartas[i] > 0){
					if(i > 9){
						if(m + 10 + 1 <= 23) return i+1;
						return -1;
					} else {
						if(m + i + 1 <= 23) return i+1;
						return -1;
					}
				}
			}
	}
	int menor = 23 - m;
	// cout<<menor<<endl;
	if(menor <= 10 && cartas[menor-1] > 0) return menor;
	return -1;
}

void soma(int &a, int b){
	if(b > 10){
		a += 10;
	} else {
		a += b;
	}
}

int main(){
	int a; cin>>a;
	int j = 0, m = 0;
	vector<int> cartas(13, 4);
	int c, d; cin>>c>>d;
	cartas[c-1]--;
	cartas[d-1]--;
	soma(j, c); soma(j, d);
	cin>>c>>d;
	cartas[c-1]--;
	cartas[d-1]--;
	soma(m, c); soma(m, d);
	for(int i = 0; i<a; i++){
		int c; cin>>c;
		cartas[c-1]--;
		soma(j, c);
		soma(m, c);
	}
	// cout<<j<<" "<<m<<endl;
	cout<<solve(j, m, cartas)<<endl;
}