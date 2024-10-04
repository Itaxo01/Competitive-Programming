#include <bits/stdc++.h>
#define mod 1000000007;
using namespace std;
const int MAX_SIZE = 1501;
vector<int>isprime(MAX_SIZE , true);
vector<int>prime;
vector<int>SPF(MAX_SIZE);
map<int, vector<int>> graph;
bitset<1000001> visitado = {0};

void sieve(int N){
    isprime[0] = isprime[1] = false;
    for (int i=2; i<N ; i++){
        if (isprime[i]){
            prime.push_back(i);
            SPF[i] = i;
        }
        for (int j=0; j < (int)prime.size() && i*prime[j] < N && prime[j] <= SPF[i]; j++){
            isprime[i*prime[j]]=false;
            SPF[i*prime[j]] = prime[j] ;
        }
    }
}

vector<int> fatores(int n){
	vector<int> v;
	int sqr = (int)ceil(sqrt(n))+1;
	for(int i = 0; i<prime.size() && i<sqr; i++){
		if(n%prime[i]==0){
			v.push_back(prime[i]);
			do n/=prime[i]; while(n%prime[i]==0);
		}
	}
	if(v.size()==0) v.push_back(n);
	return v;
}

void dfs(int n, int &count){
	visitado.set(n);
	for(int e:graph[n]){
		if(visitado[e]==0){
			count++;
			dfs(e, count);
		}else if(e==n) count++;
	}
	return;
}

long long fastPow(long long n, long long m){
	long long res = 1;
	while(m>0){
		if(m & 1) res = (res*n)%mod;
		n = (n*n)%mod;
		m >>= 1;
	} return res;
}

void resolve(int n, int total){
	if(n!=1){
		vector<int> fact = fatores(n);
		visitado.reset();
		int count = 0;
		for(int e:fact){
			dfs(e, count);
		}cout<<fastPow(2, total-count)<<endl;
	}else{
		cout<<fastPow(2, total)<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve(MAX_SIZE);

	int n; cin>>n;
	for(int i = 0; i<n; i++){
		int prato; cin>>prato;
		vector<int> prato_f = fatores(prato);
		for(int j = 0; j<prato_f.size(); j++){
			if(graph.find(prato_f[j])==graph.end()) graph[prato_f[j]] = {};
			graph[prato_f[j]].push_back(prato);
		}
	}

	int pessoas; cin>>pessoas;
	for(int i = 0; i<pessoas; i++){
		int pessoa; cin>>pessoa;
		resolve(pessoa, n);
	}
}