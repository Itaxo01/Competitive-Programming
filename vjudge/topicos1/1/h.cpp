#include <bits/stdc++.h>
using namespace std;
/*IDEAS: 
	Instead of focusing on the direction of the switch, we can store just a value for each position that
	is the sum up until this point, where the we sum the right turns and subtract the left ones. We can 
	already store this value mod s.size() (remember that -1 mod 5 == 4 mod 5), that is what matters.
	
	After that, we need to determine for which values of dislocation the string s remains the same
	for example:
		abab -> rotate two times to the right -> abab -> rotate more two times -> abab. Which means
		both 2 mod 4 and 0 mod 4 results on the string beeing the same
	With that in mind, if, for instance, the only value where of rotation that is equal to the original
	is 0 mod n, we know that, in the interval between two k mod n the sum total is 0 mod n, which means
	+1 on the final answer. We can just count the number of times a num k appears on the vector (during
	a interval without inverting).
	But, if more numbers*/
int main(){
	string s; cin>>s;
	int n; cin>>n;
	for(int i = 0; i<n; i++){
		char c; cin>>c;
		if(c != 'I'){
			int b; cin>>b;
		}
	}
}