#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b){
  return a + rand()%(b - a + 1);
}
// Generate a random input for the sh script. Should be modified based on the real problem.
int main(int argc, char *argv[]){
  srand(atoi(argv[1]));

  int t = rand(3, 10);
  cout<<t<<endl;
  while(t--){
	int n = rand(1, 1000);
	int q = rand(1, 1000);
	cout<<n<<" "<<q<<endl;

	for(int i = 0; i<n; i++){
		cout<<rand(1, 1e9)<<" ";
	}
	for(int i = 0; i<q; i++){
		cout<<rand(1, 1000)<<" "<<rand(1, n)<<endl;
	}
  }

}