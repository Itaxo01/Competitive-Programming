#include <bits/stdc++.h>
using namespace std;


void solve(vector<int> &v, int a, int start, set<int> &s){
    s.insert(a);
    for(int i = start; i < v.size(); i++){
        solve(v, a * v[i], i + 1, s);
    }
}

vector<int> preffix_function(const string &s){
    int n = s.size(); vector<int> b(n+1);
    b[0] = -1; int i = 0, j = -1;
    while (i < n){
        while(j >= 0 && s[i] != s[j]) j = b[j];
        b[++i] = ++j;
    }
    return b;
}

int kmp(const string &t, const string &p){
    vector<int> b = preffix_function(p);
    int n = t.size(), m = p.size();
    int j = 0;
    int counter = 0;
    for(int i = 0; i<n; i++){
        while(j >= 0 && t[i] != p[j]) j = b[j];
        j++;
        if(j == m) {
            // Aqui ele já encontrou a string, se quiser a primeira ocorrência
            // só dar break, se quiser contar, só botar um count, etc
            j = b[j];
            counter++;
        }
    }
    return counter;
}

bool verify(string &a, int b){
    int d1 = a.size()/b;
    int d2 = kmp(a, a.substr(0, b));
    return d1 == d2;
}

int main(){
    while(true){
        string a; cin>>a;
        if(a== ".") break;
        int n = a.size();
        // Achar todos os divisores de n:
        vector<int> v;
        while(n % 2 == 0){
            n/=2;
            v.push_back(2);
        }
        for(int i = 3; i*i<=a.size(); i+=2){
            while(n % (i) == 0){
                v.push_back(i);
                n/=(i);
            }
        }
        if(n > 2) v.push_back(n);
        set<int> s;
        solve(v, 1, 0, s);
        
        // for(int e: s) cout<<e<<" ";
        // cout<<endl;
        int p = -1;
        for(int e: s){
            p = a.size()/e;
            if(verify(a, e)) break;
        }
        cout<<p<<endl;
    }
}