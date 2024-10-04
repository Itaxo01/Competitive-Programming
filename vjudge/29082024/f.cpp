#include <bits/stdc++.h>
int height[100000];
int dist[100000];

using namespace std;

bool check(int size){
	for(int i = 0; i<size; i++){
		
	}
}

int main(){
	int n; cin>>n;
	for(int i = 0; i<n; i++){
		memset(height, 0, sizeof(height));
		memset(dist, 0, sizeof(dist));
		int a; cin>>a;
		int height[a];
		int dist[a-1];
		for(int j = 0; j<a; j++){
			cin>>height[j];
		}
		for(int j = 0; j<a-1; j++){
			cin>>dist[j];
		}
		if(check(a)) cout<<"habibi"<<endl;
		else cout<<"which"<<endl;
	}
}