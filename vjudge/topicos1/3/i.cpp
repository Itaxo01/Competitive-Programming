#include <bits/stdc++.h>
using namespace std;

int mod(int a, int b){
	return (a%b+b)%b;
}
unordered_map<string, int> dias = {
	{"Mon", 0},
	{"Tue", 1},
	{"Wed", 2},
	{"Thu", 3},
	{"Fri", 4},
	{"Sat", 5},
	{"Sun", 6}
};
unordered_map<int, string> dias_aux = {
	{0, "Mon"},
	{1, "Tue"},
	{2, "Wed"},
	{3, "Thu"},
	{4, "Fri"},
	{5, "Sat"},
	{6, "Sun"}
};

int simulate(int day, int a){
	while(day != 0 && day != 2 && day != 4){
		int renova = 30 + ((day == 4) + 2*(day == 3));
		if(renova >= a) return renova-a;
		a -= renova;
		day = mod(day+renova, 7);
	}
	a %= 91;
	while(true){
		int renova = 30 + ((day == 4) + 2*(day == 3));
		if(renova >= a) return renova-a;
		a -= renova;
		day = mod(day+renova, 7);
	}
}

int main(){	
	// int l = 5;
	// cout<<dias_aux[l]<<endl;
	// for(int i = 0; i<20; i++){
	// 	l = mod(l+30, 7);
	// 	if(l >= 5) l = 0;
	// 	cout<<dias_aux[l]<<endl;
	// }
	string s; cin>>s; int n; cin>>n;
	int d = dias[s];
	// é possivel prever o dia em que será recolhido ou renovado o dinheiro
	// segunda -> quarta -> sexta -> segunta...
	// sábado -> segunda...
	// domingo -> terça -> quinta -> segunda...

	// Se ele caiu em uma segunda, quarta, ou sexta, ele já entra no ciclo i+2 mod 6
	// Caso ele caia em uma terça, 
	
	// A unica coisa que importa é quando que ele renovou pela ultima vez
	int menor = INT_MAX;
	for(int i = 0; i<n; i++){
		int a; cin>>a;
		int day = mod(d-a, 7);
		menor = min(menor, simulate(day, a));
	} 
	cout<<menor<<endl;
	
}