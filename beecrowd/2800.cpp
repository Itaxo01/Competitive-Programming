#include <bits/stdc++.h>

using namespace std;
int bloco[320][100001];
int normal[1000001];

void update(int id, int val, int nbloco)
{
	int bn = id/nbloco;
	bloco[bn][normal[id]]--;
	
	normal[id] = val;
	
	bloco[bn][normal[id]]++;
}

int query(int x, int y, int w, int nbloco)
{
	int sum = 0;
	int quantia = y-x;
	while(x%nbloco!=0 && x<=y){
	    if(normal[x]==w) sum++;
	    x++;
	}
	for(int i = x/nbloco; i<(y+1)/nbloco; i++) {
		sum += bloco[i][w];
		x+= nbloco;
	}
	while (x <= y) {
		if(normal[x]==w) sum++;
		x++;
	}
	return (quantia+1-sum);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m; cin>>n>>m;
	int b_id = -1;
	int nbloco = sqrt(n);
    for(int i = 0; i<n; i++){
        int b; cin>>b;
        if(i%nbloco == 0) b_id++;
		bloco[b_id][b]++;
        normal[i] = b;
    };

    for(int i = 0; i<m; i++){
        int c; cin>>c;
        if(c == 1){
            int x, w; cin>>x>>w;
            update(x-1, w, nbloco);
        }else{
            int x, y, w; cin>>x>>y>>w;
            cout<<query(x-1, y-1, w, nbloco)<<endl;
        }
    }
	return 0;
}
