#include <bits/stdc++.h>

using namespace std;


int main(){
	int n; cin>>n;
	deque<int> v0;
	deque<int> v1;
	
	while(n--){
		int a, b; cin>>a>>b;
		if(b) v1.push_back(a);
		else v0.push_back(a);
	}
	int inicio = 0;
	int t = 0;
	int sentido = 0;
	while(!v1.empty() and !v0.empty()){
		if(v1.front()>v0.front()){
			t = max(inicio, v0.front())+10;
			v0.pop_front();
			if(v0.empty()) break;
			while(v0.front()<=t){
				t = max(inicio, v0.front())+10;
				v0.pop_front();
				if(v0.empty()) break;
			}
		}else{
			t = max(inicio, v1.front())+10;
			v1.pop_front();
			if(v1.empty()) break;
			while(v1.front()<=t){
				t = max(inicio, v1.front())+10;
				v1.pop_front();
				if(v1.empty()) break;
			}
		}
		inicio = t;
	}
	inicio = t;
	while(!v1.empty()){
		t = max(inicio, v1.front())+10;
		v1.pop_front();
		if(v1.empty()) break;
		while(v1.front()<=t){
			t = max(inicio, v1.front())+10;
			v1.pop_front();
			if(v1.empty()) break;
		}
	}
	while(!v0.empty()){
		t = max(inicio, v0.front())+10;
		v0.pop_front();
		if(v0.empty()) break;
		while(v0.front()<=t){
			t = max(inicio, v0.front())+10;
			v0.pop_front();
			if(v0.empty()) break;
		}
	}
	cout<<t<<endl;
	
}