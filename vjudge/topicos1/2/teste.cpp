#include <bits/stdc++.h>
using namespace std;

bool work(){
    string s; cin>>s;
    for(int i = 0; i<s.size()-1; i++){
        if(s.substr(i, 2) == "it") return true;
    }
    return false;
}

int main(){
    int n; cin>>n;
    while(n--){
        if(work()) cout<<"YES\n";
        else cout<<"NO\n";
    }
}