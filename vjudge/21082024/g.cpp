#include <bits/stdc++.h>
using namespace std;
set<int, less<int>> s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n; cin>>n;
	int p = 0;
	for(int i = 0; i<n; i++){
		int c; cin>>c;
		s.insert(c);
	}

	while(!s.empty()){
		int s1 = *s.begin();
		s.erase(s1);
		if(s1>1) break;
		else{
			if(s1+1 == *s.begin()){
				while(s1+1 == *s.begin()){
					p++;
					s1++;
					s.erase(s1);
				}
			}
		}
		if(s.empty()) break;
		else p++;
	}
	p = ((p)%2+2)%2;
	if(p == 0) cout<<"Alicius"<<endl;
	else cout<<"Bobius"<<endl;
    return 0;
}