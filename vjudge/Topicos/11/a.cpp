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
        ll distances[a];
        for(int i = 0; i<a; ++i){
            for(int j = 0; j<a; ++j)
                distances[j] = dist(p[i], p[j]);
            sort(distances, distances+a);
            
            int rep = 1;
            for(int j = 1; j<a; j++){
                if(distances[j-1] == distances[j]) rep++;
                else {
                    count += (rep*(rep-1))/2;
                    rep = 1;
                }
            }
            count += (rep*(rep-1))/2;
        }
        cout<<count<<endl;
    }
}