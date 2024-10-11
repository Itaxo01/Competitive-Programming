#include <bits/stdc++.h>
#define ull unsigned long long int
using namespace std;
map<pair<int, int>, ull> mem;


ull trib(int n, int b){
    if(n <= 1) return 1;
    if(mem.find({n, b})!=mem.end()){
        return mem[{n, b}];
    }
    ull chamadas = 1;
    for(int i = 1; i<=b; i++){
        chamadas+=trib(n-i, b);
    }
    return mem[{n, b}] = chamadas;
}

int main(){
    int a, b;
    int c = 1;
    while(cin>>a>>b){
        if(a>61 || b>60) break;
        mem.clear();
        ull chamadas = trib(a, b);
        printf("Case %d: %llu\n", c++, chamadas);

    }
}