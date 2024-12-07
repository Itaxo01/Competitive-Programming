#include <bits/stdc++.h>
using namespace std;

int main(){
    while(true){
        string a, b; cin>>a;
        if(a == "0") break;
        cin>>b;
        int t1 = 0;
        if(b.size() >= a.size()){
            for(int i = 0; i<=b.size()-a.size(); i++){
                if(b.substr(i, a.size()) == a) t1++;
            }
        }

        int t2 = 0;
        unordered_set<string> auxs;
        if(a.size()>1 && b.size() >= a.size()-1){
            for(int k = 0; k<a.size(); k++){
                string aux = a.substr(0, k) + a.substr(k+1);
                auxs.insert(aux);
            }
            for(string aux : auxs){
                for(int i = 0; i<=b.size()-aux.size(); i++){
                    if(b.substr(i, aux.size()) == aux) t2++;
                }
            }
        }

        int t3 = 0;
        string characters = "AGCT";
        auxs.clear();
        for(char e: characters){
            for(int k = 0; k<=a.size(); k++){
                string aux = a.substr(0, k) + e + a.substr(k);
                auxs.insert(aux);
            }
        }

        if(b.size() >= a.size()+1){
            for(string aux : auxs){
                for(int i = 0; i<=b.size()-aux.size(); i++){
                    if(b.substr(i, aux.size()) == aux) t3++;
                }
            }
        }


        cout<<t1<<" "<<t2<<" "<<t3<<endl;
    }
    return 0;
}