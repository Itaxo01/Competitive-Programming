#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    for(int i = 0; i<n; i++){
        int x; cin>>x;
        int a, b; cin>>a>>b;
        set<pair<int, int>> p;
        for(int j = 0; j<b; j++){
            int c1, c2; cin>>c1>>c2;
            p.insert({min(c1, c2), max(c1, c2)});
        }
        cout<<p.size()*2<<endl;
    }
}