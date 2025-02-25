#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
using namespace std;


int d(ii a, ii b){
	return sqrt(pow(a.first-b.first, 2)+pow(a.second-b.second, 2));
}
int p(ii a, ii b){
	return abs(a.first-b.first)+abs(a.second-b.second);
}

int count_pairs(vector<ii> &v){
	int c = 0;
	for(int i = 0; i<v.size(); i++){
		for(int j = i+1; j<v.size(); j++){
			if(d(v[i], v[j]) == p(v[i], v[j])) c++;
		}
	}
	return c;
}

void work(){
    int a; cin>>a;
	
	vector<int> v;
	int amount = 0;
	while(amount != a){
		int count = 1;
		int sum = 2;
		int maior = 2;
		while(count + sum <= (a-amount)){
			count += sum;
			sum++;
			maior+=1;
		}
		v.push_back(maior);
		amount += count;
	}

	vector<ii> res;
	int maior = 1;
	int menor = 1;
	bool first = true;
	for(int e: v){
		if(first){
			first = false;
			for(int i = maior; i<maior+e; i++){
				res.push_back({menor, i});
			}
		} else
			for(int i = maior; i<maior+e-1; i++){
				res.push_back({i, menor});
			}

		maior += e;
		menor++;
	}

	 cout<<res.size()<<endl;
	 for(auto e: res){
		cout<<e.first<<" "<<e.second<<endl;
	}


}


signed main(){
    int tt; cin>>tt;
    while(tt--)
        work();

    return 0;
}