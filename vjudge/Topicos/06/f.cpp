#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, an1;
map<pair<int, int>, int> mem;
int fx(int i, int j){
    if(i == n && j == 1) return an1;
    if(mem.find({i, j})!=mem.end())
        return mem[{i, j}];
    if(i<j){
        int maior = 0;
        for(int k = i; k<j; k++)
            maior = max(maior, fx(i, k)+fx(k+1, j));
        return mem[{i, j}] = maior;
    }else{
        int f1 = 0;
        int f2 = 0;
        if(i<n){
            int maior = 0;
            for(int k = i+1; k<=n; k++)
              maior = max(fx(k, 1)+fx(k, j), maior);
            f1 = maior;
        }
        if(j>0){
            int maior = 0;
            for(int k = 1; k<j; k++)
              maior = max(maior, fx(i, k)+fx(n, k));
            f2 = maior;
        }
        return mem[{i, j}] = f1+f2;
    }
}

signed main(){
    while(cin>>n>>an1){
        mem.clear();
        cout<<fx(1, n)<<endl;
    }
}