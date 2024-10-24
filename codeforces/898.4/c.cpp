#include <bits/stdc++.h>

using namespace std;

void work(){
	int sum = 0;
	int count = 0;
	for(int i = 0; i<10; i++){
		string s; cin>>s;
		for(int j = 0; j<10; j++){
			if(s[j]=='X'){
				if(min(i, j) == 0 || max(i, j) == 9) sum+=1;
				else if(min(i, j) == 1 || max(i, j) == 8) sum+=2;
				else if(min(i, j) == 2 || max(i, j) == 7) sum+=3;
				else if(min(i, j) == 3 || max(i, j) == 6) sum+=4;
				else if(min(i, j) == 4 || max(i, j) == 5) sum+=5;	
			}
		}
	}
	cout<<sum<<endl;
}

int main(){
	int n; cin>>n;
	while(n--){
		work();
	}
}