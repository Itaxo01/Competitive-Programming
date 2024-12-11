#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll cross(pair<ll,ll> P, pair<ll,ll> Q, pair<ll,ll> R){
    //if return >0 then point R is upper of lineseg PQ else down
    return (Q.first-P.first)*(R.second-P.second)-(R.first-P.first)*(Q.second-P.second);
}
void hull(vector<pair<ll,ll> > &P,vector<pair<ll,ll> > &L,vector<pair<ll,ll> > &U){
        int j=0,k=0,n=P.size();
        sort(P.begin(),P.end());
        U.resize(2*n);
        L.resize(2*n);
        for(int i=0;i<n;i++)
            {
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