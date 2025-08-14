#include <bits/stdc++.h>
using namespace std;

// ---------- NTT (998244353, primitive root 3) ----------
const uint32_t MOD = 998244353;
const uint32_t PRIMITIVE = 3;

uint32_t mod_pow(uint32_t a, uint32_t e) {
    uint64_t r = 1, x = a;
    while (e) {
        if (e & 1) r = r * x % MOD;
        x = x * x % MOD; e >>= 1;
    }
    return (uint32_t)r;
}

void ntt(vector<uint32_t> &a, bool invert) {
    int n = (int)a.size();
    static vector<int> rev;
    static vector<uint32_t> roots{0,1};
    if ((int)rev.size() != n) {
        int k = __builtin_ctz(n);
        rev.assign(n, 0);
        for (int i = 0; i < n; i++)
            rev[i] = (rev[i>>1] >> 1) | ((i&1) << (k-1));
    }
    if ((int)roots.size() < n) {
        int k = __builtin_ctz(roots.size());
        roots.resize(n);
        while ((1<<k) < n) {
            uint32_t z = mod_pow(PRIMITIVE, (MOD-1) >> (k+1));
            for (int i = 1<<(k-1); i < (1<<k); i++) {
                roots[2*i] = roots[i];
                roots[2*i+1] = (uint64_t)roots[i] * z % MOD;
            }
            k++;
        }
    }
    for (int i = 0; i < n; i++)
        if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int len = 1; len < n; len <<= 1) {
        for (int i = 0; i < n; i += 2*len) {
            for (int j = 0; j < len; j++) {
                uint32_t u = a[i+j];
                uint32_t v = (uint64_t)a[i+j+len] * roots[len + j] % MOD;
                uint32_t x = u + v; if (x >= MOD) x -= MOD;
                uint32_t y = u + MOD - v; if (y >= MOD) y -= MOD;
                a[i+j] = x; a[i+j+len] = y;
            }
        }
    }
    if (invert) {
        reverse(a.begin() + 1, a.end());
        uint32_t inv_n = mod_pow(n, MOD-2);
        for (auto &x : a) x = (uint64_t)x * inv_n % MOD;
    }
}

vector<uint32_t> convolution(vector<uint32_t> a, vector<uint32_t> b) {
    int n1 = (int)a.size(), n2 = (int)b.size();
    if (!n1 || !n2) return {};
    int n = 1;
    while (n < n1 + n2 - 1) n <<= 1;
    a.resize(n); b.resize(n);
    ntt(a, false); ntt(b, false);
    for (int i = 0; i < n; i++) a[i] = (uint64_t)a[i] * b[i] % MOD;
    ntt(a, true);
    a.resize(n1 + n2 - 1);
    return a;
}

// ---------- factorials ----------
struct Fact {
    vector<uint32_t> fact, invfact;
    Fact(int n): fact(n+1), invfact(n+1) {
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = (uint64_t)fact[i-1] * i % MOD;
        invfact[n] = mod_pow(fact[n], MOD-2);
        for (int i = n; i > 0; i--) invfact[i-1] = (uint64_t)invfact[i] * i % MOD;
    }
};

// Computes coefficients of p(x+K) given a[0..N]
vector<uint32_t> shift_polynomial(const vector<uint32_t> &a, uint32_t K) {
    int N = (int)a.size() - 1;
    Fact F(N);
    // A[i] = a[i]/i!, C[j] = K^j / j!
    vector<uint32_t> A(N+1), C(N+1);
    for (int i = 0; i <= N; i++) A[i] = (uint64_t)a[i] * F.invfact[i] % MOD;

    uint32_t Kj = 1;
    for (int j = 0; j <= N; j++) {
        C[j] = (uint64_t)Kj * F.invfact[j] % MOD;
        Kj = (uint64_t)Kj * K % MOD;
    }

    vector<uint32_t> D = convolution(A, C);
    D.resize(N+1);
    // b[n] = D[n] * n!
    for (int n = 0; n <= N; n++) D[n] = (uint64_t)D[n] * F.fact[n] % MOD;
    return D; // coefficients of p(x+K)
}

// ---------- example usage ----------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; uint32_t K;
    cin >> N >> K; // degree N and shift K (mod 998244353)
    vector<uint32_t> a(N+1);
    for (int i = 0; i <= N; i++) cin >> a[i];

    vector<uint32_t> b = shift_polynomial(a, K);
    for (int i = 0; i <= N; i++) {
        if (i) cout << ' ';
        cout << b[i];
    }
    cout << '\n';
    return 0;
}
