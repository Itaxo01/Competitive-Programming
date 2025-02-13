#include <bits/stdc++.h>
using namespace std;

void printa(vector<char> &v){
    for(char e: v){
        cout<<e;
    }
    cout<<'\n';
}

int main(){
    string s; cin>>s;
    map<char, int> m;
    for(int i = 0; i < s.size(); i++){
        m[s[i]]++;
    }


    vector<char> new_s(s.size());

    vector<char> odds;
    for(int i = 0; i<26; i++){
        char e = 'a'+i;
        if(m[e] % 2 != 1) continue;
        odds.push_back(e);
    }
    int l = 0, r = odds.size()-1;
    while(l < r){
        m[odds[l]]++;
        m[odds[r]]--;
        l++; r--;
    }
    // for(int i = 0; i<26; i++) cout<<m['a'+i]<<endl;
    if(s.size() % 2 == 1) {
        new_s[s.size()/2] = odds[l];
        m[odds[l]]--;
    }

    l = 0, r = s.size()-1;

    for(int i = 0; i<26; i++){
        while(m['a'+i] > 0){
            new_s[l] = 'a'+i;
            new_s[r] = 'a'+i;
            m['a'+i] -= 2;
            l++; r--;

        }
    }
    printa(new_s);

    
}