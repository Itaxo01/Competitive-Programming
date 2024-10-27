#include <bits/stdc++.h>

using namespace std;

void work(){
	int a; cin>>a;
	int ar[a];
	for(int i = 0; i<a; i++){
		cin>>ar[i];
	}
	int maior = 0;
	for(int i = 0; i<a; i++){
		int count = 1;
		for(int j = i+1; j<a; j++){
			if(ar[i]>=ar[j]) count++;
		}
		maior = max(count, maior);
	}
	cout<<(a-maior)<<endl;
}

int main(){
	int n; cin>>n;
	while(n--){
		work();
	}
}