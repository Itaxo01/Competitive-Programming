#include <bits/stdc++.h>
using namespace std;

string s;

bool cmp(int a, int b){
    string sa = s.substr(a), sb = s.substr(b);
    return lexicographical_compare(sa.begin(), sa.end(), sb.begin(), sb.end());
}

int main(){
    while(getline(cin, s)){
        string nums; getline(cin, nums);
        stringstream ss(nums);

        int n; ss>>n;
        vector<int> v(s.size());
        for(int i = 0; i<s.size(); i++){
            v[i] = i;
        }
        sort(v.begin(), v.end(), cmp);

        for(int i = 0; i<n; i++){
            int a; ss>>a;
            if(!i) cout<<v[a];
            else cout<<" "<<v[a];
        } cout<<endl;
    }
}