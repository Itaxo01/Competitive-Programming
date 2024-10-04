#include <bits/stdc++.h>

using namespace std;
int main(){
	int a, b; cin>>a>>b;
	int maior = 0;
	for(int i = 0; i<a; i++){
		int c; cin>>c;
		if(c==b){
			maior = c;
			break;
		}
		else if(c<b and c>maior) maior = c;
	}
	cout<<maior<<endl;
}