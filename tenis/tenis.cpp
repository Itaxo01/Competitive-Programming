#include <bits/stdc++.h>

using namespace std;
int main(){

	vector<int> A;
	for(int i; i<4; i++){
		int a; cin>>a;
		A.push_back(a);
	}
	sort(A.begin(), A.end());
	int r = abs((A[0]+A[3])-(A[1]+A[2]));
	cout<<r<<endl;

	return 0;
}