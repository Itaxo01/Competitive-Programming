#include <bits/stdc++.h>
using namespace std;


int main(){
	int n; cin>>n;
	// ela só precisará esperar até outro dia para uma consulta se houver mais de um médico naquele dia.
	// no pior dos casos, ela terá que esperar 1e6 dias, pois se todos começarem no dia 1000 e terem o mesmo ciclo de 1000, ela visitará um a cada 1000 dias totalizando os 1e6. 

	vector<bool> v;
	bitset<1001006> bs;
	bs.reset();
	int menor = 0;

	vector<pair<int, int>> d(n);
	for(auto &[a, b]: d){ 
		// aqui vou só simular qual o primeiro livre.
		cin>>a>>b;
		while(bs[a] || a < menor) a+=b;
		menor = a;
		bs.set(a);
	}
	cout<<menor<<endl;

}