#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> v;

bool cmp(int a, int b){
	return v[a] > v[b];
}
void work(){
	int n; cin>>n;
	v.resize(n);
	vector<int> pos(n);
	for(int i = 0; i<n; i++){
		cin>>v[i];
		pos[i] = i;
	}
	sort(pos.begin(), pos.end(), cmp);
	int count = 0, next = 0;
	int res = 0;
	vector<bool> visitado(n, false);
	while(count < n){
		count++;
		res++;
		int p1 = pos[next]-1, p2 = pos[next]+1;
		visitado[pos[next]] = true;
		while(p1 >= 0 && !visitado[p1] && v[p1] <= v[p1+1]){
			count++; visitado[p1] = true;
			p1--;
		}
		while(p2 < n && !visitado[p2] && v[p2] <= v[p2-1]){
			count++; visitado[p2] = true;
			p2++;
		}
		while(next < n && visitado[pos[next]] == true) next++;
	}

	cout<<res<<endl;


}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	while(n--){
		work();
	}	
}