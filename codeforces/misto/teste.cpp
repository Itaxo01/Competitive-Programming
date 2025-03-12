#include <bits/stdc++.h>
#define vpii vector<pair<int, int>>
using namespace std;

class Solution {
	public:

		int query(vector<vpii> &v, int l, int r){

		}
		// This will be a recursive function.
		int solve(vector<vpii> &v, vector<int> &h, int l, int r){
			// The idea is that every time this function is called, We identify the
			// smallest number in h (l, r). That way we will split the array in two
			// and the return value should be 
			// max(solve(h, l, k-1), solve(h, k+1, r), (r-l) * ks);
			// where k is the position and ks the value;
			if(r < l) return 0;
			int k = query(v, l, r);
		}
		
		int largestRectangleArea(vector<int>& h) {
			int n = h.size();
			vector<vpii> v(n, vpii((int)log2(n)+1));

			vector<int> log(n+1, 0);
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
		}
	};