#include <bits/stdc++.h>
using namespace std;


int main(){
	int tt; cin>>tt;
	while(tt--){
		string s; cin>>s;
		// Vamos tentar postular algo aqui:
		// Se a pessoa K é a que roubou, ela pode ou não estar mentindo. Porém só ela poderá mentir, e isso implica que todas as outras pessoas anteriormente falaram a verdade.
		// Caso K-1 e K+1 falem a mesma coisa que K (1 ou 0), é por que K falou a verdade. 

		// o ultimo 1 sempre poderá ter mentido. Também dessa forma, antes dele todo mundo falou a verdade.
		// se a string começar em 0 é por que o primeiro é o unico a mentir.
		
		
		// ignorando o que está em cima, pensei em que todo mundo entre o ultimo 1 e o primeiro 0 (inclusos) estão mentindo
		int n = s.size();
		int one = -1, zero = -1;
		for(int i = 0; i<n; i++){
			if(zero == -1 && s[i] == '0') {
				zero = i;
			}
			if(s[i] == '1') one = i;
		}
		if(one != -1 && zero != -1){
			if(one < zero) cout<<abs(zero-one)+1<<endl;
		} else if(one != -1){
			cout<<n-one<<endl;
		} else if(zero != -1){
			cout<<zero+1<<endl;
		} else cout<<n<<endl;
	}
}