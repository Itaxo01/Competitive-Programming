#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b; cin>>a>>b;
    string s = "Rerisson";
    map<string, int> m;
    map<int, string> nomes;

    nomes[m.size()] = s;
    m[s] = m.size();
    vector<vector<int>> v(1001);
    for(int i = 0; i<a; i++){
        string s1, s2; cin>>s1>>s2;
        if(m.find(s1) == m.end()) {
            nomes[m.size()] = s1;    
            m[s1] = m.size();
        }
        if(m.find(s2) == m.end()) {
            nomes[m.size()] = s2;    
            m[s2] = m.size();
        }
        v[m[s1]].push_back(m[s2]);
        v[m[s2]].push_back(m[s1]);
    }
    set<string> convidados;

    int count = 0;
    queue<pair<int, int>> q; q.push({0, 0});
    vector<bool> visitados(1001, false);
    visitados[0] = true;

    while(!q.empty()){
        auto p = q.front(); q.pop();
        for(int e: v[p.first]) {
            convidados.insert(nomes[e]);
            if(p.second < b-1 && !visitados[e]){
                q.push({e, p.second+1});
                visitados[e] = true;
            }
        }
    }
    if(convidados.find(s) != convidados.end()) convidados.erase(s);
    cout<<convidados.size()<<endl;
    for(auto e: convidados){
        cout<<e<<endl;
    }
}