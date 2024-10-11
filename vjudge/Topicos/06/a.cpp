#include <bits/stdc++.h>

using namespace std;


int main(){
    int n; cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int custo[n];
    custo[0] = 0;
    custo[1] = abs(arr[1]-arr[0]);
    for(int i = 2; i<n; i++){
        custo[i] = min((abs(arr[i]-arr[i-1])+custo[i-1]),
                        abs(arr[i]-arr[i-2])+custo[i-2]);
    }
    cout<<custo[n-1]<<endl;

}