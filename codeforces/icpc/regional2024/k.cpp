#include <bits/stdc++.h>
using namespace std;

bool res;
int a;
bitset<101> bs1;
void solve(int st, int sum, vector<int> &c, bitset<101> bs, int size, int pos){
	
	if(size == (a+1)/2){
		// cout<<sum<<endl;
		if(sum == st/2){
			res = true;
			// cout<<bs<<endl;
			bs1 = bs;
		}
		return;
	}else if(sum>=st || (a-pos+size) < (a+1)/2) return;
	if(res) return;
	solve(st, sum, c, bs, size, pos+1);
	bs.set(pos);
	solve(st, sum+c[pos], c, bs, size+1, pos+1);
	
}


int main(){
	cin>>a;
	int sum = 0;
	vector<int> c(a);

	for(int i = 0; i<a; i++){
		cin>>c[i];
		sum+=c[i];
	}
	sort(c.begin(), c.end());

	res = false;
	bitset<101> bs; bs.reset();

	solve(sum, 0, c, bs, 0, 0);
	if(!res) cout<<-1<<endl;
	else{
		vector<int> v1;
		vector<int> v2;
		for(int i = 0; i<a; i++){
			if(bs1.test(i)) v1.push_back(c[i]);
			else v2.push_back(c[i]);
		}
		int sum1 = 0, sum2 = 0;
		sort(v2.rbegin(), v2.rend());
		int i = 0, j = 0;
		
		for(int k = 0; k<a; k++){
			if(k) cout<<" ";
			if(sum1<sum2){
				cout<<v1[i]; 
				sum1+=v1[i];
				i++;
			}else{
				cout<<v2[j]; 
				sum2+=v2[j];
				j++;
			}
		}
		
		cout<<endl;
		// cout<<sum1<<" "<<sum2<<endl;
	}
}