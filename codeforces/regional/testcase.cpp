#include <bits/stdc++.h>

using namespace std;

int main(){
	int n = 100;
	cout<<n<<endl;
	for(int i = 0; i<n; i++){
		if(i==0)
			cout<<rand()%1000000+1;
		else 
			cout<<" "<<rand()%1000000+1;
	}cout<<endl;
	cout<<n<<endl;
	for(int i = 0; i<n; i++){
		cout<<rand()%1000000+1<<endl;
		
	}
	
}