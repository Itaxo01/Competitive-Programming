#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	
	for(int i = 0; i<n; i++){
		int a = 0, b = 0;
		int p = 0;
		string s; cin>>s;
		int c = 0;
		for(char e:s) if(e=='0') c++;
		while(s.size()>c){
			char anterior;
			int maior = 0;
			int inicio = 0, fim = 0;
			int count = 0;
			char* q = s.data();
			for(int j = 0; j<s.size(); j++){
				if(q[j]=='1' and anterior == '1'){
					count++;
				}
				else if(q[j] == '1'){
					anterior = q[j];
					count = 1;
				}
				else{
					if(count>maior){
						maior = count;
						inicio = j-count;
						fim = inicio+count;
						count = 0;
					}
					anterior = '0';
				}
			}
			if(count>maior){
				maior = count;
				inicio = s.size()-count;
				fim = inicio+count;
			}
			s = s.substr(0, inicio)+s.substr(fim);
			if(p%2==0) a+=maior;
			else b+=maior;
			p++;
		}
		cout<<a<<endl;

	}
}