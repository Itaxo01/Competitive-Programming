#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	int n; cin>>n;
	while(n--){
		int a, b; cin>>a>>b;
		// int fam[a];
		int singles = 0;
		int happy = 0;
		for(int i = 0; i<a; i++){
			// cin>>fam[i];
			int c; cin>>c;
			int oc = c/2;
			b-=oc;
			happy+=oc*2;
			singles+=c%2;
		}
		while(b*2>singles && singles>0){
			b--;
			happy++;
			singles--;
		}
		cout<<happy<<endl;
	}
}