#include <bits/stdc++.h>
using namespace std;

int main(){
    int tt; cin>>tt;
    while(tt--){
        int a; cin>>a;
        vector<int> v(a);
        int last_pos = 0;
        for(int i = 0; i<a; i++){
            int b; cin>>b;
            int res = 1;
            int f1 = 1;
            int f2 = 1;
            int fib = 1;
            while(fib != b){
                fib = f1+f2;
                f2 = f1;
                f1 = fib;
                res++;
            }
            v[i] = res;
            last_pos = max(last_pos, res);
        }

        string s; getline(cin, s);
        getline(cin, s);
        int i = 0;
        while(i < s.size()){
            if(s[i] >= 'A' && s[i] <= 'Z') {
                i++;
                continue;
            }
            s.erase(s.begin()+i);
        }
        string s1 = "";
        for(int i = 0; i<101; i++){
            s1 += " ";
        }
        for(int i = 0; i<a; i++){
            s1[v[i]-1] = s[i]; 
        }
        cout<<s1.substr(0, last_pos)<<endl;
    }
}