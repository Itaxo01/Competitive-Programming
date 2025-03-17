#include <bits/stdc++.h>
#define vpii vector<pair<int, int>>
#define vi vector<int> 
using namespace std;

class Solution {
	public:

		pair<int, int> query(vi &log, vector<vpii> &v, int l, int r){
			int k = log[r-l+1];
			auto p = min(v[l][k], v[r - (1<<k)+1][k]);
			return p;
		}

		// This will be a recursive function.
		int solve(vi &log, vector<vpii> &v, vector<int> &h, int l, int r){
			// The idea is that every time this function is called, We identify the
			// smallest number in h (l, r). That way we will split the array in two
			// and the return value should be 
			// max(solve(h, l, k-1), solve(h, k+1, r), (r-l) * ks);
			// where k is the position and ks the value;
			if(r < l) return 0;
			if(r == l) return h[r];
			auto k = query(log, v, l, r);
			int a = solve(log, v, h, l, k.second-1);
			int b = solve(log, v, h, k.second+1, r);
			int c = k.first*(r-l+1);
			return max(a, max(b, c));
		}
		int largestRectangleArea(vector<int>& h) {
			int n = h.size();
			vector<vpii> v(n, vpii((int)log2(n)+1));
			// We are going to build a sparse table for a fast RMQ lookup,
			// and store the values with a pair to have acess to the relative position
			vi log(n+1, 0);
			for(int i = 2; i<=n; i++){
				log[i] = log[i/2] + 1;
			}

			for(int i = 0; i<n; i++){
				v[i][0].first = h[i];
				v[i][0].second = i;
			}

			for (int j = 1; (1 << j) <= n; j++) {
				for (int i = 0; i + (1 << j) <= n; i++) {
					v[i][j] = min(v[i][j - 1], v[i + (1 << (j - 1))][j - 1]);
				}
			}
			return solve(log, v, h, 0, h.size()-1);
		}
};

int main(){
	vector<int> h = {2,4};
	Solution sol;
	cout<<sol.largestRectangleArea(h)<<endl;
	
}