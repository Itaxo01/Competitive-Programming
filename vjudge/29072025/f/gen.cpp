// preset for generating a random tree that can be used for debugging 
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b){
  return a + rand()%(b - a + 1);
}

int N, M, K, root;
const int MAXN = 50;
const int MAXM = (int)1e5;
const int MAXK = (int)1e6;


int main(int argc, char *argv[]){
  srand(atoi(argv[1]));
	
	N = rand(2, MAXN); // num of vertices 
	M = rand(0, MAXM);
	K = rand(1, MAXK);
	// always N-1 edges.
	root = 1; // Aqui a raiz é aleatória, mas pode ser fixa em 1 se preciso
	cout<<N<<" "<<M<<" "<<K<<endl;

	for(int i = 0; i<M; i++){
		int u = rand(1, N);
		int v = rand(1, N);
		int t = rand(1, 5);
		cout<<u<<" "<<v<<" "<<t<<endl;
	}
}
