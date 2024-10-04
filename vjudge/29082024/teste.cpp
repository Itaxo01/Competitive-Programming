#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 60;
    cout<<n<<endl;
    for(int i = 60; i>=1; i--){
        cout<<i;
        for(int j = i; j>0; j--) cout<<" "<<j;
        cout<<endl;
    }

}