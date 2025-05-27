#include <bits/stdc++.h>
using namespace std;


int main(){
	int a; cin>>a;
	string s1, s2; cin>>s1>>s2;
	int p1 = 0, p2 = 0;
	for(int i = 0; i<a; i++){
		if(s1[i] == '*') p1++;
		if(s2[i] == '*') p2++;
	}

	printf("%.2lf\n", 1-p2/(double)p1);
}