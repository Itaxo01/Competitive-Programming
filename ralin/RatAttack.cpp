#include <bits/stdc++.h>

using namespace std;
int killed[1025][1025] = {0};

int main(){
	int n; cin>>n;
	while(n--){
		memset(killed, 0, sizeof(killed[0][0])*1025*1025);
		// cout<<killed[50][50]<<endl;
		
		int d; cin>>d;
		int a; cin>>a;
		int maior = 0;
		int maior_x = 0, maior_y = 0;
		for(int i = 0 ; i < a; i++){
			int x, y, p; cin>>x>>y>>p;
			for(int k = max(0, x-d); k<= min(1024, x+d); k++){
				for(int j = max(0, y-d); j <= min(1024, y+d); j++){
					killed[k][j]+=p;
					if(killed[k][j]>maior){
						maior = killed[k][j];
						maior_x = k; maior_y = j;
					}else if(killed[k][j]==maior){
						if(maior_x==k){
							if(maior_y>j){
								maior_y = j;
							}
						}else if(maior_x>k){
							maior_x = k;
							maior_y = j;
						}
					}
				}
			}
		}
		cout<<maior_x<<" "<<maior_y<<" "<<maior<<endl;
	}
}