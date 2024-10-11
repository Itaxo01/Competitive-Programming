#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    int c = 1;
    while(n--){
        int a; cin>>a;
        int h[a];
        int w[a];
        for(int i = 0; i<a; i++) cin>>h[i];
        for(int i = 0; i<a; i++) cin>>w[i];
        
        int d[a] = {0};
        int maior_h = 0;
        for(int i = 0; i<a; i++){
            d[i] = w[i];
            maior_h = max(d[i], maior_h);
            for(int j = 0; j<i; j++){
                if(h[i]>h[j]){
                    d[i] = max(d[i], d[j]+w[i]);
                    maior_h = max(d[i], maior_h);
                }
            }
        }
        memset(d, 0, a);
        int maior_w = 0;
        for(int i = 0; i<a; i++){
            d[i] = w[i];
            maior_w = max(d[i], maior_w);
            for(int j = 0; j<i; j++){
                if(h[i]<h[j]){
                    d[i] = max(d[i], d[j]+w[i]);
                    maior_w = max(d[i], maior_w);
                }
            }
        }
        printf("Case %d. ", c++);
        if(maior_h>=maior_w){
            printf("Increasing (%d). Decreasing (%d).\n", maior_h, maior_w);
        }else{
            printf("Decreasing (%d). Increasing (%d).\n", maior_w, maior_h);
        }
    }
}