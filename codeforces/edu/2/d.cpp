#include <bits/stdc++.h>
using namespace std;
struct point{
    int x, y;
    point(int a = 0, int b = 0) {
        x = a; y = b;
    }
};

int dist_sq(point a, point b){
    return pow(a.x-b.x, 2) + pow(a.y-b.y, 2);
}

long double area(point a, point b, int r1, int r2){
    long double area = 0.0;
    int d = dist_sq(a, b);
    if(d >= pow(r1+r2, 2)) return area;
    if(d <= pow(r1-r2, 2)) return min(r1, r2)*min(r1, r2)*M_PI;
}

int main(){
    point a, b; int r1, r2;
    cin>>a.x>>a.y>>r1;
    cin>>b.x>>b.y>>r2;
    cout<<area(a, b, r1, r2)<<endl;
}