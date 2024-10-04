#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    vector<int> r(n), d(n); 
    for(int j = 0; j<n; j++){
        cin>>r[j];
	}
    for(int j = 0; j<n; j++){
        cin>>d[j];
    }
    int trocas = 0;
    
	for(int i = 0; i<n-1; i++){
        while(d[i]!=i+1){
            int temp = d[d[i]-1];
            d[d[i]-1] = d[i];
            d[i] = temp;
            ++trocas;
	    }
        while(r[i]!=i+1){
            int temp = r[r[i]-1];
            r[r[i]-1] = r[i];
            r[i] = temp;
            ++trocas;
        }
    }
    cout<<trocas<<endl;
}