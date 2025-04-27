	#include <bits/stdc++.h>
	#define int long long
	using namespace std;

	int gcd(int a, int b){
		if(b == 0) return a;
		return gcd(b, a%b);
	}

	void work(){
		int n; cin>>n;
		vector<int> v(n);
		int menor = -1;
		int menor_pos = -1;
		for(int i = 0; i<n; i++){
			cin>>v[i];
			if(v[i] < menor || menor == -1){
				menor = v[i];
				menor_pos = i;
			}
		}
		vector<int> t;
		for(int i = 0; i<n; i++){
			if(i != menor_pos && v[i] % menor == 0) t.push_back(v[i]);
		}
		int g = -1;
		if(t.size() > 1){
			g = gcd(t[0], t[1]);
			for(int i = 2; i<t.size(); i++){
				g = gcd(g, t[i]);
			}
		} else if(t.size() > 0){
			g = t[0];
		}
		if(g == menor) cout<<"Yes";
		else cout<<"No";
		cout<<endl;
	}

	signed main(){
		int tt; cin>>tt;
		while(tt--){
			work();
		}
	}