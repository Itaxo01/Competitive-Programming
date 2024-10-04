#include <bits/stdc++.h>


using namespace std;
int main(){
	while(1){
		int n; cin>>n;
		if(n==0) break;
		priority_queue<int> pq;
		for(int i = 0; i<n; i++){
			int a; cin>>a;
			pq.push(-a);
		}
		int total = 0;
		while(pq.size()>1){
			int temp = abs(pq.top());
			pq.pop();
			temp += abs(pq.top());
			pq.pop();
			pq.push(-temp);
			total+= temp;
			
		}
		cout<<total<<endl;
	}
}