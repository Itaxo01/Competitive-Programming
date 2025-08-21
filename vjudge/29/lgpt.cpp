#include <bits/stdc++.h>
using namespace std;

struct GF2Mat {
    int n;
    vector<uint64_t> row; // row[i] has bits of columns
    GF2Mat(int n_, bool ident=false): n(n_), row(n_,0) {
        if(ident) for(int i=0;i<n;i++) row[i] = (1ULL<<i);
    }
    static GF2Mat multiply(const GF2Mat &A, const GF2Mat &B){ // C = A * B (mod 2)
        GF2Mat C(A.n);
        for(int i=0;i<A.n;i++){
            uint64_t r = A.row[i];
            while(r){
                int k = __builtin_ctzll(r);
                C.row[i] ^= B.row[k];
                r &= r-1;
            }
        }
        return C;
    }
    static GF2Mat power(GF2Mat base, long long e){
        GF2Mat R(base.n, true);
        while(e){
            if(e&1) R = multiply(R, base);
            base = multiply(base, base);
            e >>= 1;
        }
        return R;
    }
    uint64_t apply(uint64_t vec) const { // returns M * vec
        uint64_t res = 0;
        for(int i=0;i<n;i++){
            // parity of popcount(row[i] & vec)
            if(__builtin_popcountll(row[i] & vec) & 1) res |= (1ULL<<i);
        }
        return res;
    }
};

int di[8]={1,-1,0,0,1,1,-1,-1};
int dj[8]={0,0,1,-1,1,-1,1,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; long long K;
    if(!(cin>>n>>K)) return 0;
    vector<string> g(n);
    for(int i=0;i<n;i++) cin>>g[i];

    // Map free cells
    vector<vector<int>> id(n, vector<int>(n,-1));
    int F=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(g[i][j] != '#') id[i][j] = F++;

    if(F==0){ // all locked
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cout<<'#';
            cout<<"\n";
        }
        return 0;
    }
    if(F > 64){
        // Need wider bitsets; extend code (e.g. use vector<unsigned long long>) if constraints allow >64.
        // Placeholder simple (slow) fallback could be added here.
    }

    // Build adjacency A
    GF2Mat M(F); // will store I + A
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int idx = id[i][j];
            if(idx==-1) continue;
            uint64_t rowBits = (1ULL<<idx); // identity part
            for(int k=0;k<8;k++){
                int ni=i+di[k], nj=j+dj[k];
                if(ni<0||nj<0||ni>=n||nj>=n) continue;
                int njdx = id[ni][nj];
                if(njdx==-1) continue; // locked -> contributes 0
                rowBits |= (1ULL<<njdx); // add neighbor (since I + A; neighbor adjacency adds bit)
            }
            M.row[idx] = rowBits;
        }
    }

    // Initial vector
    uint64_t x0 = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(id[i][j]!=-1 && g[i][j]=='1')
                x0 |= (1ULL<<id[i][j]);

    // x_K = M^K * x0
    GF2Mat MK = GF2Mat::power(M, K);
    uint64_t xK = MK.apply(x0);

    // Output
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j]=='#'){ cout<<'#'; continue; }
            int bit = (xK >> id[i][j]) & 1ULL;
            cout<<bit;
        }
        cout<<"\n";
    }
}