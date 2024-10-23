#include <bits/stdc++.h>

using namespace std;

signed main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, q;
        cin >> n >> q;
        vector<int> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i], p[i]--;

        vector<int> alr(n, 0);
        
		alr[0] == (p[0] == 1);
        int i = 0;
        int currentPos = 0;
        for (int num : p) {
            
            if (num > i) { 
                i = max(i, num);
            }
            if (i == currentPos)
                alr[i] = 1;
            currentPos++;
        }

        string s;cin >> s;

        set<int> locks;
        for (int i = 0; i < n-1; i++) {
            if (s[i] == 'L' && s[i+1] == 'R' && !alr[i]) locks.insert(i);
        }

        while (q--) {
            int i;
            cin >> i;
            i--;

            if (s[i] == 'L') {
                s[i] = 'R';
                if (locks.count(i)) locks.erase(i);
                if (s[i-1] == 'L') {
                    if (!alr[i-1]) locks.insert(i-1);
                }
            }

            else {
                s[i] = 'L';
                if (locks.count(i-1)) locks.erase(i-1);
                if (s[i+1] == 'R') {
                    if (!alr[i]) locks.insert(i);
                }

            }
            if (locks.size()) cout << "NO" << '\n';
            else cout << "YES" << '\n';
        }

    }
    
    return 0;
}