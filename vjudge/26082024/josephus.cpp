#include <bits/stdc++.h>


using namespace std;

int jose(int n){
	if(n == 1) return 1;
	if(n%2 == 1) return (2*(jose(n/2)+1)/2-1);
	else return (2*(jose(n/2)+1)/2);
}

using namespace std;
int main(){
	int cases; cin>>cases;
	int	instancia = 1;
	for(int j = 0; j<cases; j++){
		int a; cin>>a;
		cout<<"n: "<<a<<", Winner: "<<jose(a)<<endl;
	}
}