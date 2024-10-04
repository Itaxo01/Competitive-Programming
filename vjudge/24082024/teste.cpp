#include <iostream>

using namespace std;

int main(){
	int n = 1e6;
	int mod = 1e9;
	cout<<n<<endl;
	for(int i = 0; i<n-1; i++){
		cout<<rand()%mod<<" ";
	}
	cout<<rand()%mod<<endl;
	cout<<rand()%mod<<" "<<rand()%mod<<endl;
}