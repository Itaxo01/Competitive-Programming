#include <bits/stdc++.h>
#define int long long
using namespace std;

void work(){
	int a[3]; for(int i = 0; i<3; i++) cin>>a[i];
	int v; cin>>v;
	sort(a, a+3);
	int maior = 0;
	for(int i = a[0]; i>0; i--){
		for(int j = a[1]; j>0; j--){
			if(v%(i*j) == 0){
				int h = v/(i*j);
				int b[3] = {i, j, h};
				sort(b, b+3);
				if(b[0]>a[0] || b[1]>a[1] || b[2]>a[2]) continue;
				int total = (a[0]-b[0]+1)*(a[1]-b[1]+1)*(a[2]-b[2]+1);
				
				maior = max(maior, total);
			}
		}
	}
	cout<<maior<<endl;
}

signed main(){
	int n; cin>>n;
	while(n--){
		work();
	}
}