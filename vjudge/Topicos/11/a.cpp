#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline ll dist(pair<ll, ll> &a, pair<ll, ll> &b){
    return (a.first - b.first)*(a.first - b.first) + 
        (a.second - b.second)*(a.second - b.second);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(true){
        int a; cin>>a;
        if(!a) break;
        vector<pair<ll, ll>> p(a);
        for(int i = 0 ; i<a; i++){
            cin>>p[i].first>>p[i].second;
        }
        int count = 0;
        for(int i = 0; i<a; ++i){
            unordered_map<ll, int> d;
            for(int j = 0; j<a; ++j){
                int d_ = dist(p[i], p[j]);
                count += d[d_]++;
            }
        }
        cout<<count<<endl;
    }
}