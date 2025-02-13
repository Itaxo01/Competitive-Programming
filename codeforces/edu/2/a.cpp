#include <bits/stdc++.h>
using namespace std;

bool is_a(string s){
    if(s.size() == 0) return false;
    for(int i = 0; i<s.size(); i++){
        if(!isdigit(s[i])) return false;
    }
    if(s.size() > 1 && s[0] == '0') return false;
    return true;
}

void printa(vector<string> &v){
    if(v.size() == 0) {
        cout<<"-\n";
        return;
    }
    cout<<"\"";
    bool first = true;
    for(string e: v){
        if(!first) cout<<',';
        cout<<e;
        first = false;
    }
    cout<<"\"\n";
}

int main(){
    string s; cin>>s;
    vector<string> a;
    vector<string> b;
    int last_string = 0;
    for(int i = 0; i<s.size(); i++){
        if(s[i] != ',' && s[i] != ';') continue;
        string word = s.substr(last_string, i-last_string);
        last_string = i+1;

        if(is_a(word)) a.push_back(word);
        else b.push_back(word);
    }
    string word = s.substr(last_string, s.size()-last_string);
    if(is_a(word)) a.push_back(word);
    else b.push_back(word);

    printa(a);
    printa(b);
}