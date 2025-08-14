#include <bits/stdc++.h>

using namespace std;

#define int long long
const int INF = 0x3F3F3F3F;
using ii = pair<int, int>;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()





const bool DEBUG = true;

const int MOD = 1e9+7;

struct Matrix {
    int l, c;
    vector<vector<ll>> m;
    Matrix(int l, int c) : l(l), c(c) {
        m.assign(l, vector<ll>(c, 0));
    }

    Matrix operator* (Matrix &o) {
        Matrix res(l, o.c);
        for (int i = 0; i < l; i++)
            for (int j = 0; j < o.c; j++)
                for (int k = 0; k < c; k++)
                    res[i][j] = (res[i][j] + m[i][k] * o[k][j]) % MOD;
        return res;
    }

    vector<ll>& operator[](int idx) {
        return m[idx];
    }

    Matrix pow(ll e) {
        if (e == 0) return identity(l);
        if (e == 1) return *this;
        Matrix squared = (*this) * (*this);
        if (e % 2 == 0) return squared.pow(e/2);
        return squared.pow(e/2) * (*this);
    }

    Matrix identity(int sz) {
        Matrix mm(sz, sz);
        for (int i = 0; i < sz; i++)
            mm[i][i] = 1;
        return mm;
    }
};

inline int mul(int a, int b) { return a * b % MOD; }

int pwr(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1) r = mul(r, a);
        a = mul(a, a);
        b >>= 1;
    }
    return r;
}

int inv(int x) {
    return pwr(x, MOD-2);
}

signed main() {

    cin.tie(0)->sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;

    Matrix mat(5*n, 5*n);

    auto getId = [&](int u, int t) { return 5*u+t; };

    vector<vector<ii>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        u--; v--;
        adj[u].push_back({t, v});
        adj[v].push_back({t, u});
    }

    for (int i = 0; i < n-1; i++) {
        int from = getId(i, 0);
        int invsz = inv(adj[i].size());
        for (auto[w, v] : adj[i]) {
            int to = getId(v, w-1);
            mat[from][to] = (mat[from][to] + invsz) % MOD;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int t = 1; t <= 4; t++) {
            int from = getId(i, t);
            int to = getId(i, t-1);
            mat[from][to] = 1;
        }
    }

    int end = getId(n-1, 0);
    mat[end][end] = 1;


	 auto t1 = std::chrono::high_resolution_clock::now();

    mat = mat.pow(k);
	 
	 auto t2 = std::chrono::high_resolution_clock::now();
	 auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	 cerr << "Time taken: " << duration << " ms" << endl;
    cout << mat[0][end] << '\n'; 
	 
    return 0;
}