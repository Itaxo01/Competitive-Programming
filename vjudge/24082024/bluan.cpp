#include<bits/stdc++.h>
#define ll long long
using namespace std;

int mod(int n, int m){
	return ((n%m)+m)%m;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n; cin>>n;
	deque<int> values;
	deque<int> values1;
	int possible = 0;
	for (int i = 0; i < n; i++) {
		int val; cin>>val;
		values.push_back(val);
		values1.push_back(val);

		possible = (possible+val)%2;
	}

	int costLeft, costRight; cin>>costLeft>>costRight;

	if (possible%2 != 0) {
		cout<<-1<<endl;
		return 0;
	}

	ll cost = 0;
	for (int i = 0; i < n; i++) {
		if (values[i] % 2 == 1) {
			int firstOddRight = -1;
			int firstOddLeft = -1;
			int distLeft = 0;
			int distRight = 0;
 
			for (int j = 1; j < n; j++) {
				if (values[mod(i+j, n)] % 2 == 1) { 	
					firstOddRight = mod(i+j, n);
					distRight = j;
					break;
				}
			}

			for (int j = 1; j < n; j++) {
				if (values[mod(i-j, n)] % 2 == 1) {
					firstOddLeft = mod(i-j, n);
					distLeft = j;
					break;
				}
			}

			int cLeft = min(distLeft*costRight, distLeft*costLeft);
			int cRight = min(distRight*costRight, distRight*costLeft);
			if (cLeft <= cRight) { 
				cost += cLeft;
				values[i] = 2;
				values[firstOddLeft] = 2;
			} else {
				cost += cRight;
				values[i] = 2;
				values[firstOddRight] = 2;
			}

		}
	}


	ll cost2 = 0;
	for (int i = n-1; i >= 0; i--) {
		if (values1[i] % 2 == 1) {
			int firstOddRight = -1;
			int firstOddLeft = -1;
			int distLeft = 0;
			int distRight = 0;
 
			for (int j = 1; j < n; j++) {
				if (values1[mod(i+j, n)] % 2 == 1) { 	
					firstOddRight = mod(i+j, n);
					distRight = j;
					break;
				}
			}

			for (int j = 1; j < n; j++) {
				if (values1[mod(i-j, n)] % 2 == 1) {
					firstOddLeft = mod(i-j, n);
					distLeft = j;
					break;
				}
			}

			int cLeft = min(distLeft*costRight, distLeft*costLeft);
			int cRight = min(distRight*costRight, distRight*costLeft);
			if (cLeft <= cRight) { 
				cost2 += cLeft;
				values1[i] = 2;
				values1[firstOddLeft] = 2;
			} else {
				cost2 += cRight;
				values1[i] = 2;
				values1[firstOddRight] = 2;
			}

		}
	}


	cout<<min(cost2, cost)<<endl;
	return 0;
}