#include<bits/stdc++.h>
using namespace std;
struct point{
    int x, y;
    point(int a, int b): x(a), y(b) {}
    point(): x(0), y(0) {}
    bool operator < (point a){
        return x<a.x || (x == a.x && y < a.y);
    }
};

int cross(point P, point Q, point R){
    //if return >0 then point R is upper of lineseg PQ else down
    return (Q.x-P.x)*(R.y-P.y)-(R.x-P.x)*(Q.y-P.y);
}
void hull(vector<point> &P,vector<point> &L,vector<point> &U){
    int j=0,k=0,n=P.size();
    sort(P.begin(),P.end());
    U.resize(2*n);
    L.resize(2*n);
    for(int i=0;i<n;i++){
        while(j>=2 && cross(L[j-2],L[j-1],P[i])<=0)//p[i] is making right turn we need left turn
            j--;
        while(k>=2 && cross(U[k-2],U[k-1],P[i])>=0)//p[i] is making left turn we need right
            k--;
        L[j++]=P[i];
        U[k++]=P[i];
    }
    U.resize(k);
    L.resize(j);
}

int main(){
    while(true){
        int a, b, c; cin>>a>>b>>c;
        if(!a && !b && !c) break;
        vector<point> cops;
        vector<point> robbers;
        vector<point> citizens;

        for(int i = 0; i<a; i++){
            point p; cin>>p.x>>p.y;
            cops.push_back(p);
        }
        for(auto p: cops)
            printf("%d, %d\n", p.x, p.y);
        
        vector<point> L;
        vector<point> U;
        hull(cops, L, U);

        for(int i = 0; i<b; i++){
            point p; cin>>p.x>>p.y;
            robbers.push_back(p);
        }
        // for(auto p: L)
        //     printf("%d, %d\n", p.x, p.y);
        // for(auto p: U)
        //     printf("%d, %d\n", p.x, p.y);

        for(int i = 0; i<c; i++){
            point p; cin>>p.x>>p.y;
            citizens.push_back(p);
        }
    }
}
