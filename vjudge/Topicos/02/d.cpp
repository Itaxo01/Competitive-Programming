#include <bits/stdc++.h>


using namespace std;
int main(){
	while(true){
		int n; cin>>n;
		if(n==0) break;
		queue<int> q;
		for(int i = 1; i<=n; i++){
			q.push(i);
		}
		vector<int> discard;
		while(q.size()>1){
			discard.push_back(q.front());
			q.pop();
			q.push(q.front());
			q.pop();
		}
		cout<<"Discarded cards:";

		for(int i = 0; i<discard.size(); i++){
			if(i==0) cout<<" "<<discard[i];
			else cout<<", "<<discard[i];
		}cout<<endl;
		cout<<"Remaining card: "<<q.front()<<endl;
	}
}