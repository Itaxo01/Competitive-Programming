#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e6;
int t[4* maxn];
int num[maxn];


void construct(int v, int l, int r){
	if (l == r) {
		t[v] = num[l]; 
		return;
	}

	int mid = l + (r - l)/2;

	construct(2*v, l, mid);
	construct(2*v+1, mid+1, r);
	t[v] = t[2*v] ^ t[2*v+1];
}


int find(int v, int l, int r, int tl, int tr) {
	if (l > tr || r < tl) return 0;
	if (l == tl && tr == r) return t[v];

	int mid = tl + (tr - tl)/2;
	
	return find(v*2, l, r, tl, mid) ^ (v*2+1, l,r,mid+1, tr);
}

int main(){
	int n; cin>>n;
	while(n--){
		int a, b;
		cin>>a>>b;
		int **arr = new int*[200001];
		for(int i = 0; i<200001; i++){
            arr[i] = new int[200001];
        }
		memset(arr, -1, sizeof(arr));
		vector<int> v(a);
		for(int i = 0; i<a; i++){
			cin>>v[i];
		}
		for(int i = 0; i<b; i++){
			int l, r; cin>>l>>r;
			cout<<tes(l-1, r-1, v)<<endl;
		}
	}
}