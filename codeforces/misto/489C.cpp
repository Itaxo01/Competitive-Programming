#include <bits/stdc++.h>

using namespace std;

void printa(vector<int> &v){
	for(int i = 0; i<v.size(); i++){
		cout<<v[i];
	}
}

int main(){
	int a, b; cin>>a>>b;
	if(b == 0 && a == 1) cout<<"0 0\n";
	else if(b == 0 || a*9 < b) cout<<"-1 -1\n";
	else {
		vector<int> menor(a, 0);
		menor[0] = 1;
		int aux = b;
		aux -= 1;
		int i = a-1;
		while(i > 0 && aux) {
			menor[i] = min(9, aux);
			aux -= min(9, aux);
			i--;
		}
		if(aux) menor[0] += aux;
		vector<int> maior(a, 0);
		maior[0] = min(9, b);
		b -= min(9, b);
		i = 1;
		while(i < a && b) {
			maior[i] = min(9, b);
			b -= min(9, b);
			i++;
		}
		printa(menor); cout<<" "; printa(maior);
		cout<<endl;



	}
}