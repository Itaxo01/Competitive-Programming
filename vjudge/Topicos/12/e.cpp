#include <bits/stdc++.h>
using namespace std;

int at(vector<int> &r, int t){
    if(t >= r.size()) return -1;
    return r[t];
}

vector<int> suffix_array(string &s){
    int n = s.size();
    vector<int> r(n), p(n);
    for(int i = 0; i<n; i++){
        p[i] = i;
        r[i] = int(s[i]);
    }
    int k;
    
    for(k = 1; k<=n; k<<=1){
        sort(p.begin(), p.end(), 
            [&](int i, int j) {
                return make_pair(r[i], at(r, i+k)) < make_pair(r[j], at(r, j+k));
            }
        );
        int c = 0;
        vector<int> aux(n);
        aux[p[0]] = c;
        for(int i = 1, j = 0; i<n; i++, j++){
            aux[p[i]] = (make_pair(r[p[i]], at(r, p[i]+k)) == make_pair(r[p[j]], at(r, p[j]+k))) 
                            ? c : ++c;
        }
        swap(r, aux);
        if(r[p[n-1]] == n-1) break;
    }
    return r;
}

int main(){
    string s;
    while(getline(cin, s)){
        vector<int> r = suffix_array(s);

        string nums; getline(cin, nums);
        stringstream ss(nums);
        int n; ss>>n;
        
        vector<int> v(s.size());
        for(int i = 0; i<v.size(); i++){
            v[i] = i;
        }

        sort(v.begin(), v.end(), [&](int a, int b){
            return r[a] < r[b];
        });
        for(int i = 0; i<n; i++){
            int a; ss>>a;
            if(!i) cout<<v[a];
            else cout<<" "<<v[a];
        } cout<<endl;
    }
}