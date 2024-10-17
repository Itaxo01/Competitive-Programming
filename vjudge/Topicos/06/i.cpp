#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

int main(){
    int n; cin>>n;
    int m[MAX+1], c[101];
    while(n--){
		int a, b; cin>>a>>b;
        for(int i = 0; i < b; i++)
            cin>>c[i];
        for(int i = 0; i < MAX+1; i++)
            m[i] = MAX;
        m[0] = 0;

        for(int i = 0; i < b; i++)
            for(int j = MAX; j > 0; j--)
                if(c[i] <= j){
					m[j] = min(m[j], m[j - c[i]]+1);
				}
        int i;
        for(i = a; m[i] == MAX; i++);

        printf("%d %d\n", i, m[i]);
    }

	return 0;
}