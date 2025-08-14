#include <bits/stdc++.h>
#define ll long long
#define all(v) v.begin(), v.end()
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n; cin>>n;
	vector<int> v(n);
	for(int &e: v) cin>>e;

	// o primeiro passo seria atingir o maior MEX possível
	// vou fazer isso de uma forma meio estupida já que o máximo será 1e5
	map<int, ll> m;
	for(int e: v) m[e]++;

	ll sum = 0;
	ll mex = 0;
	for(int i = 0; i<n; i++){
		// consigo atingir MEX = i? 
		if(m.find(i) != m.end() && m[i] > 0) {
			mex++; 
			continue;
		}
		else {
			mex = i;
			// verifico se há alguém acima que posso descer
			auto it = m.lower_bound(i);
			if(it != m.end()){
				sum += mex*(it->first - i);
				it->second --;
				if(it->second == 0) m.erase(it);
				m[i]++;
				mex++; // caso o loop acabe na próxima iteração.
			} else break; // não tenho mais como aumentar o MEX
		}
	}
	
	// Aqui o MEX já está otimizado, vou tentar me livrar de todos que não contribuem para o mex enquanto mantenho o MEX máximo.

	if(mex > 1){
		sum += mex;
		for(auto &[a, b]: m){
			if(b > 1){
				sum += a*mex*(b-1);
			}
		}
		mex--;
	}

	// daqui em diante a cada passo terei que diminuir meu MEX
	// porém como não tenho mais elementos inuteis, o meu MEX também representa a quantidade de elementos que eu possuo. 
	while(mex>1){
		sum += (mex)*(mex);
		mex--;
	}



	cout<<sum<<endl;
}