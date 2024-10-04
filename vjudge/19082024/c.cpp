#include <bits/stdc++.h>
#define ll long long

using namespace std;

// int printDivisors(int n, int k){
//     // Note that this loop runs till square root
// 	int cont = 0;
//     for (int i = 1; i <= sqrt(n); i++) {
//         if (n % i == 0 ) {
// 			if (n/i > k) {
// 				cout<<n/i<<endl;
// 				continue;
// 			}
//             // If divisors are equal, print only one
//             if (n / i != i)
// 				cont+=2;
//         }
//     }
// 	return cont;
// }

int printDivisors(int n, int k)
{
    // Note that this loop runs till square root
	int cont=0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // If divisors are equal, print only one
            if (n / i == i)
                cont++;
            else{
				cont++;
				if (n/i <= k)cont++;
			} 
        }
    }
	return cont;
}

int main(){
	int cases;cin>>cases;
	while(cases--){
		int n,t;cin>>n>>t;
		t--;

		if (t==0)
			cout<<n<<endl;
		else
			cout<<printDivisors(t,n)<<endl;
	
	}
}
