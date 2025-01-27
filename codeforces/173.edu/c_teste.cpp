//oamh namoh bhagwate vaudevaye namah//
#include <bits/stdc++.h>
 
using namespace std;
 
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cout << "(" << #_VA_ARGS_ << "):", dbg_out(_VA_ARGS_)
#else
#define dbg(...)
#endif
 
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define INF 1e9
 
const int MAX_N = 2e5+5;
const ll MOD = 1000000007;
const ld EPS = 1e-9;
 
const long long MAXAI = 1000000000000ll;
 
ll power(ll a,ll b){
  if(b==0)return 1;
 
  ll ans=power(a,b/2);
  ans*=ans;
  ans%=MOD;
 
  if(b%2!=0){
    ans*=a;
    ans%=MOD;
  }
 
  return ans;
 
}
 
bool cmp(pair<ll,ll> &p1,pair<ll,ll> &p2){
    if(p1.first<p2.first)return true;
    if(p1.first==p2.first){
        if(p1.second>p2.second)
            return true;
    }
    return false;
}

vector<bool> sieve(int n)
{
    vector<bool> prime(n+1,true);
 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    return prime;
}

ll modInverse(ll A, ll M)
{
    ll m0 = M;
    ll y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1) {
        ll q = A / M;
        ll t = M;

        // m is remainder now, process same as
        // Euclid's algo
        M = A % M, A = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
        x += m0;

    return x;
}

class DSU{
  private:
    vector<ll> par;
    vector<ll> rank;

  public:
    DSU(int size) : par(size),rank(size,1){
      for(int i=0;i<size;i++){
        par[i]=i;
      }
    }

    int find(int x){
      if(par[x]==x)return x;
      return par[x] = find(par[x]);
    }

    bool unite(int x,int y){
      int rootx=find(x);
      int rooty=find(y);
      if(rootx==rooty) return false;
      if(rank[rootx]<rank[rooty])swap(x,y);
      rank[rootx]+=rank[rooty];
      par[rooty]=rootx;
      return true;
    }
};


int main() {
  #ifndef ONLINE_JUDGE
      freopen("error.txt" , "w" , stderr);
      freopen("input.txt" , "r" , stdin);
      freopen("output.txt" , "w" , stdout);
  #endif
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  int tc=1;
  // sieve();
  cin >> tc;
  int start_s=clock() ; 
  for (int tx = 1; tx <= tc; tx++){
    ll n;
    cin>>n;
    vector<ll> a(n);
    int ind=-1;
    ll x=0;
    for(int i=0;i<n;i++){
      cin>>a[i];
      if(a[i]!=-1 && a[i]!=1){
        x=a[i];
        ind=i;
      }
    }
    ll max_sum=0;
    ll min_sum=0;
    ll sum=0;
    ll prev=0;
    if(a[0]==1 || a[0]==-1){
      sum=a[0];
      prev=a[0];
    }
    for(int i=1;i<n;i++){
      // cout<<prev<<" "<<sum<<" "<<max_sum<<" "<<min_sum<<endl;
      if(i==ind){
        max_sum=max(max_sum,sum);
        min_sum=min(min_sum,sum);
        sum=0;
        prev=0;
      }
      else if(a[i]==prev){
        sum+=a[i];
      }
      else{
        // cout<<"here "<<i<<" "<<sum<<endl;
        max_sum=max(max_sum,sum);
        min_sum=min(min_sum,sum);
        sum=a[i];
        prev=a[i];
      }
    }
    max_sum=max(max_sum,sum);
    min_sum=min(min_sum,sum);
    // cout<<max_sum<<" "<<min_sum<<endl;
    vector<ll> ans;
    map<ll,ll> mpp;
    for(int i=min_sum;i<=max_sum;i++){
      ans.push_back(i);
      mpp[i]=1;
    }
    if(ind!=-1){
      ll max_1=0;
      ll max_2=0;
      ll min_1=0; 
      ll min_2=0;
      sum=0;
      for(int i=ind-1;i>-1;i--){
        sum+=a[i];
        max_1=max(max_1,sum);
        min_1=min(min_1,sum);
      }
      sum=0;
      for(int i=ind+1;i<n;i++){
        sum+=a[i];
        max_2=max(max_2,sum);
        min_2=min(min_2,sum);
      }
      for(int i=(min_1+min_2);i<=(max_1+max_2);i++){
        if(mpp.find(x+i)==mpp.end()){
          ans.push_back(x+i);
          mpp[x+i]=1;
        }
      }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
      cout<<ans[i]<<" ";
    }cout<<endl;
  }
  int stop_s=clock(); 
  // cout<<(stop_s-start_s)/double(CLOCKS_PER_SEC)*1000; 
  return 0;
}
 
/*
  
*/