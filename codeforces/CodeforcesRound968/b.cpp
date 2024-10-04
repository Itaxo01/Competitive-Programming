#include <bits/stdc++.h>

using namespace std;
bool cmp(pair<int, int>& a, pair<int, int>& b){
    return a.second < b.second;
}

int main(){
	int n; cin>>n;
	for(int i = 0; i<n; i++){
		int a; cin>>a;
		deque<pair<int, int>> v(a);
		for(int j = 0; j<a; j++){
			int c;cin>>c;
			v[j] = {j, c};
		}
		sort(v.begin(), v.end(), cmp);
		int p = 0;
		while(v.size()>1){
			if(p%2==0){
				pair<int, int> e = v[v.size()-1];
				int id = ((e.first-1)%v.size()+v.size())%v.size();
				int temp = max(e.second, v[id].second);
				v[id].second = temp;
				v.erase(v[size])
			}
			else{

			}
			p++;
		}
		cout<<endl;
	}
}