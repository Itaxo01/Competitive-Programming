#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool cmp(pair<int, int> a, pair<int,int> b){
	return a.second < b.second;
}

void work(){
	int a; cin>>a;
	int count = 0;
	map<int, int> mem;
	int sum = 0;
	vector<pair<int, int>> seg;
	for(int i = 0; i<a; i++){
		int c; cin>>c;
		sum+=c;
		if(sum == 0) seg.push_back({0, i});
		if(mem.find(sum)!=mem.end()){
			seg.push_back({mem[sum]+1, i});
		}
		mem[sum] = {i};
		
	}
	sort(seg.begin(), seg.end(), cmp);
	int last = -1;
	for(auto e: seg){
		if(e.first > last){
			count++;
			last = e.second;
		}
	}

	cout<<count<<endl;
}

int main(){
	int n; cin>>n;
	while(n--){
		work();
	}
}