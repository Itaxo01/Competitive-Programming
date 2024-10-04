#include <bits/stdc++.h>


using namespace std;
int main(){
	while(true){
		int n; cin>>n;
		if(n==0) break;
		while(true){
			int a; cin>>a;
			if(a==0) break;
			stack<int> station_a;
			station_a.push(a);
			for(int i = 0; i<n-1; i++){
				cin>>a;
				station_a.push(a);
			}
			stack<int> station_b;
			stack<int> station;
			int atual = n;
			while(!station_a.empty()){
				if(station_a.top()==atual){
					atual--;
					station_b.push(station_a.top());
					station_a.pop();
				}else if(!station.empty()){
					if(station.top()==atual){
						station_b.push(station.top());
						atual--;
						station.pop();
					}else{
						station.push(station_a.top());
						station_a.pop();
					}
				}else{
					station.push(station_a.top());
					station_a.pop();
				}
			}
			bool resposta = true;
			while(!station.empty()){
				if(station.top() == atual){
					atual--;
					station_b.push(station.top());
					station.pop();
				}else{
					resposta = false;
					break;
				}
			}
			if(resposta) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		cout<<endl;
	}
	return 0;
}