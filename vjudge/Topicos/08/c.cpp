#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b, vector<int> &v, vector<bool> &visitado){
	queue<pair<int, int>> q;
	q.push({a, 0});
	
	while(!q.empty()){
		int t1 = q.front().first, t2 = q.front().second;
		q.pop();
		if(t1 == b){
			return t2;
		}
		for(int e: v){
			int n = (t1 + e)%10000;
			if(!visitado[n]){
				visitado[n] = true;
				q.push({n, t2+1});
			}
		}
	}
	return -1;
}
int main(){
	int count = 1;
	while(true){
		int a, b, c;
		cin>>a>>b>>c;
		if(!a && !b && !c) break;

		vector<int> v(c);
		for(int i = 0; i<c; i++){
			cin>>v[i];
		}
		vector<bool> visited(10001, false);

		int res = solve(a, b, v, visited);
		printf("Case %d: ", count++);
		if(res == -1) cout<<"Permanently Locked"<<endl;
		else cout<<res<<endl;
	}
	
}