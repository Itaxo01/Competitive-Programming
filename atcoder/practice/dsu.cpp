#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;

int parent[MAXN];
int sz[MAXN];

int find(int a){
	if(a == parent[a]) return a;
	return parent[a] = find(parent[a]);
}

void join(int a, int b){
	a = find(a), b = find(b);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	parent[b] = a;
}


int main(){
	int n, q; cin>>n>>q;
	for(int i = 0; i<MAXN; i++){
		parent[i] = i;
		sz[i] = 1;
	}

	for(int i = 0; i<q; i++){
		int a, b, c; cin>>a>>b>>c;
		if(!a){
			join(b, c);
		} else{
			cout<<(find(b)==find(c))<<endl;
		}
	}


}