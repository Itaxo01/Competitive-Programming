#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin>>n>>m;
    vector<int> a(n), b(m);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }for(int i = 0; i<m; i++){
        cin>>b[i];
    }

    sort(a.begin(), a.end());
    for(int i = 0; i<m; i++){
        int pos = distance(a.begin(), upper_bound(a.begin(), a.end(), b[i]));
        if(i) cout<<" ";
        cout<<pos;
    }
    cout<<endl;
}