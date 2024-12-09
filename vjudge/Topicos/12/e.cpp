#include <bits/stdc++.h>
using namespace std;



int main(){
    string s;
    while(getline(cin, s)){
        string nums; getline(cin, nums);
        stringstream ss(nums);
        
        // s.erase(s.end()-1);
        int n; ss>>n;
        map<string, int> m;
        for(int i = 0; i<s.size(); i++){
            string aux = s.substr(i);
            m[aux] = i;
        }

        for(int i = 0; i<n; i++){
            int a; ss>>a;
            auto it = m.begin();
            for(int j = 0; j < a; j++) it++;
            if(!i) cout<<(*it).second;
            else cout<<" "<<(*it).second;
        } cout<<endl;
    }
}