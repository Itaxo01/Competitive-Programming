#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    int n = 1e5;
    int q = 1e5;
    int v = 1e6;
    cout << n << endl;
    for(int i = 1; i <= n; i++){
        cout << i << " ";
    }
    cout << q << endl;
    
    random_device rd;
    mt19937 rng(rd());  // Mersenne Twister RNG
    uniform_int_distribution<int> dist(0, v-1);

    for(int i = 1; i <= q; i++){
        cout << dist(rng) <<endl;
	}
}