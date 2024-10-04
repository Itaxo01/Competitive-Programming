#include <bits/stdc++.h>

using namespace std;

bool cmp(char a, char b){
    cout<<"? "<<a<<" "<<b<<endl;
    fflush(stdout);
    char s;
    cin>>s;
    if(s=='>') return false;
    return true;
}

int main(){

    int n, q;
    cin>>n>>q;
    vector<char> v(n);
    for(int i = 0; i<n; i++){  
        v[i] = (char)('A'+i);        
    }
    sort(v.begin(), v.end(), cmp);
    cout<<"! ";
    
    for(int i = 0 ; i<n; i++){
        cout<<v[i];
    }cout<<endl;
    fflush(stdout);
}