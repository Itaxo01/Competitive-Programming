#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <n>" << endl;
        return 1;
    }
    
    int n = atoi(argv[1]);
    if (n < 1 || n > 100000) {
        cerr << "n must be between 1 and 100000" << endl;
        return 1;
    }
    
    // Seed with current time
    srand(time(nullptr));
    
    cout << n << endl;
    
    // Generate tree by randomly assigning parents
    // For a tree with n nodes (0 to n-1), we need n-1 edges
    // Node 0 is the root, so nodes 1 to n-1 need parents
    for (int i = 1; i < n; i++) {
        // Parent of node i can be any node from 0 to i-1
        int parent = rand() % i;
        cout << parent + 1 << endl; // Convert to 1-indexed, each on new line
    }
    
    // Generate random string of length n-1
    string s = "";
    for (int i = 0; i < n-1; i++) {
        char c = 'a' + (rand() % 26); // Random lowercase letter
        s += c;
    }
    cout << s << endl;
    
    return 0;
}
