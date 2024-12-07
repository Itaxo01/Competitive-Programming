#include <bits/stdc++.h>
using namespace std;

int main(){
    int tt; cin>>tt;
    while(tt--){
        int a, b; cin>>a>>b;
        vector<string> v;
        for(int i = 0; i<b; i++){
            string c; cin>>c;
            if(v.empty()) v.push_back(c);
            else {
                if(v[i-1] != c) v.push_back(c);
            }
        }
        string res = v[0];
        for(int i = 1; i < v.size(); i++){
            string s = v[i];
            int k = res.size()-s.size();
            int ks = 0;
            int count = 0;
            int salva_k = -1;
            while(k<res.size()){
                count = 0;
                if(salva_k == -1) k = res.find(s[0], k);
                else k = salva_k;
                ks = 0;
                salva_k = -1; bool first = true;
                if(k == -1) break;
                while(k < res.size() && ks < s.size() && res[k] == s[ks]){
                    k++;
                    ks++;
                    count++;
                    if(first && res[k] == s[0]) {
                        salva_k = k;
                        first = false;
                    }
                }
            }
            // cout<<count<<endl;
            res += s.substr(count);
        }
        cout<<res.size()<<endl;
    }
}