#include <bits/stdc++.h>

using namespace std;
int main(){
	int n; cin>>n;
	int cases = 1;
	while(n--){
		cout<<"Case "<<cases<<": ";
		cases++;
		queue<string> s;
		for(int i = 0; i<52; i++){
			string st; cin>>st;
			s.push(st);
		}
		int y = 0;
		for(int i = 0; i<3; i++){
			string t = s.front();
			int x;
			if(isdigit(t[0])) x = t[0]-'0';
			else x = 10;
			y+=x;
			for(int i = 0; i<=(10-x); i++){
				s.pop();
			}
		}
		for(int i = 0; i<y-1; i++){
			s.pop();
		}
		cout<<s.front()<<endl;
	}
}