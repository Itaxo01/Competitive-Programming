#include <bits/stdc++.h>
#define ld double
using namespace std;

bool cmp(const pair<ld, pair<int, int>> &a, const pair<ld, pair<int, int>> &b){
	return a.first < b.first;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	ld a = 0, b = 0;
	vector<ld> q(n);
	vector<ld> custo_a(n), custo_b(n);
	vector<pair<ld, pair<int, int>>> pq(n);
	for(int i = 0; i<n; i++){
		int A, U, B, W; cin>>A>>U>>B>>W;	
		q[i] += U; q[i] += W;
		a += A*U; b += B*W;
		custo_a[i] = A;
		custo_b[i] = B;
		if(A < B) pq[i] = {A/(ld)B, {1, i}};
		else pq[i] = {B/(ld)A, {0, i}};
	}
	sort(pq.begin(), pq.end(), cmp);
	ld c = 0;
	for(auto p: pq){
		int i = p.second.second;
		ld aux;
		if(p.second.first && a){
			aux = min(q[i], a/custo_a[i]);
			q[i] -= aux;
			c+= aux*custo_a[i];
			a -= aux*custo_a[i];
			if(q[i]){
				b -= q[i]*custo_b[i];
				c+= q[i]*custo_b[i];
			}
		} else {
			aux = min(q[i], b/custo_b[i]);
			q[i] -= aux;
			c+= aux*custo_b[i];
			b -= aux*custo_b[i];
			if(q[i]){
				a -= q[i]*custo_a[i];
				c+= q[i]*custo_a[i];
			}
		}
	}
	printf("%.15f\n", c);
}