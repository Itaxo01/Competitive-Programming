#include <bits/stdc++.h>

using namespace std;

int query(int x, int y, vector<string> v){
	if (v[x][0]==v[y][0] || v[x][1]==v[y][1] || v[x][0]==v[y][1] || v[x][1]==v[y][0]) return abs(y-x);
 
	int ans = INT_MAX;
	bool menor = false;
	bool achou = false;
	int lim = 0;
	if(x>y) swap(x, y);
	for(int i = x+1; i<v.size(); i++){
		if(i!=y){
			if(v[i]!=v[x] and v[i]!=v[y]){
				if(i>x and i<y) menor = true;
				else lim = i-y;
				achou = true;
				ans = abs(i-x)+abs(y-i);
				break;
			}
		}
	}
	if(!menor){
    	if(achou){
        	for(int i = x-1; i>=max(x-lim, 0); i--){
        		if(i!=y){
        			if(v[i]!=v[x] and v[i]!=v[y]){
        				ans = min(ans, abs(i-x)+abs(y-i));
        				break;
        			}
        		}
        	}
    	}
    	else{
    	    for(int i = x-1; i>=0; i--){
        		if(i!=y){
        			if(v[i]!=v[x] and v[i]!=v[y]){
        				ans = min(ans, abs(i-x)+abs(y-i));
        				break;
        			}
        		}
        	}
    	}
	}
	
	if(ans == INT_MAX) return -1;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin>>n;
	for(int i = 0; i<n; i++){
		int a, b; cin>>a>>b;
		vector<string> v(a);
		for(int j = 0; j<a; j++){
			string s; cin>>s;
			v[j] = s;
		}
		for(int j = 0; j<b; j++){
			int c, d; cin>>c>>d;
			cout<<query(c-1, d-1, v)<<endl;
		}
	}
}