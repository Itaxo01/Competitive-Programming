#include <bits/stdc++.h>


using namespace std;
inline bool check(int i, int j, int k, int a, int b){
	if(i+j+k==a){
		if(i*j*k==b) return true;
	}
	return false;
}

int main(){
	int n; cin>>n;
	while(n--){
		int a, b, c;
		cin>>a>>b>>c;
		int u_b = 100;
		vector<vector<int>> xyz;
		bool answ = false;
		for(int i = -u_b; i<=u_b && !answ; i++){
			for(int j = i+1; j<=u_b && !answ; j++){
				for(int k = j+1; k<=u_b && !answ; k++){
					if(pow(i, 2)+pow(j, 2)+pow(k, 2)==c){
						if(check(i, j, k, a, b)){
							cout<<i<<" "<<j<<" "<<k<<endl;
							answ = true;
							break;
						}
					}
				}	
			}
		}
		if(!answ) cout<<"No solution."<<endl;
		
	}
}