#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.second<b.second;	
}

int main(){
	int a; cin>>a;
	vector<pair<int, int>> intervalos(a);
	for(int i = 0; i<a; i++){
		cin>>intervalos[i].first>>intervalos[i].second;
	}
	sort(intervalos.begin(), intervalos.end(), cmp);
	int counter = 0;
	
}