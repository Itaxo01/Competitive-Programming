#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
using namespace std;

void work(){
	int a; cin>>a;
	int maior = 0;
	int maior_id = -1;
	int ultimo_menor = -1;
	vector<int> v(a);
	for(int i = 0; i<a; i++){
		cin>>v[i];
	}

	for(int i = 0; i<a; i++){
		int count = 0;

		for(int j = i+1; j<a; j++){
			if(v[i] > v[j]) count++;
			else if(v[i] < v[j]) count--;

			if(count > maior){
				maior = count;
				maior_id = i;
				ultimo_menor = j;
			}
		}
	}

	if(maior_id == -1) cout<<"1 1\n";
	else cout<<maior_id+1<<" "<<ultimo_menor+1<<endl;
}


signed main(){
    int tt; cin>>tt;
    while(tt--)
        work();

    return 0;
}