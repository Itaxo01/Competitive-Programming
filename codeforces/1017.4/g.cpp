#include <bits/stdc++.h>
#define int long long
using namespace std;
void rotate(deque<int> &d, int t){
	if(t == 1){
		int aux = d.back();
		d.pop_back();
		d.push_front(aux);
	} else {
		int aux = d.front();
		d.pop_front();
		d.push_back(aux);
	}
}
void work(){
	int q; cin>>q;
	int hash = 0;
	int hash_invertido = 0;
	int sum = 0;
	int size = 0;
	bool is_inverted = false;
	deque<int> d, d_inverted;
	for(int i = 0; i<q; i++){
		int a; cin>>a;
		if(a == 1){ // 1*1 2*2 3*3  1*2 2*3 3*4 // 3 2 1 -> 2 1 3
			hash = hash+sum - (size)*d[size-1];
			hash_invertido = hash_invertido - sum + (size)*d_inverted[0];
			rotate(d, 1);
			rotate(d_inverted, -1);
			// 6 3 1 2 4 5
			// 1 2 3 -> 3 1 2
			// 3 2 1 -> 2 1 3
			// quando desloca, soma 1x de todo mundo e desconta (size)x do ultimo
		} else if(a == 2){
			// (size-1)*a1 + (size-2)*a2 ... + (size - (size-1)) * an
			int aux = hash;
			hash = hash_invertido;
			hash_invertido = hash;

			is_inverted = !is_inverted;
		} else if(a == 3){
			int b; cin>>b;
			size++;
			d_inverted.push_front(b);
			d.push_back(b);
			sum += b;
			hash += b*size;
			hash_invertido += sum;
		}
		cout<<hash<<endl;

	}

}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt; cin>>tt;
	while(tt--){
		work();
	}
}