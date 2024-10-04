#include <bits/stdc++.h>
using namespace std;

int sqr(int &a){
	return a*a;
}
int distpow(pair<int, int> &a, pair<int, int> &b){
    int a_ = abs(a.first-b.first);
	int b_ = abs(a.second-b.second);
	return sqr(a_)+sqr(b_);
}

bool center(pair<int, int> &a, pair<int, int> &b, pair<int, int> &c, pair<int, int> &d){

    
	int x12 = a.first - b.first;
    int x13 = a.first - c.first;

    int y12 = a.second - b.second;
    int y13 = a.second - c.second;

    int y31 = c.second - a.second;
    int y21 = b.second - a.second;

    int x31 = c.first - a.first;
    int x21 = b.first - a.first;

    int sx13 = sqr(a.first) - sqr(c.first);
    int sy13 = sqr(a.second) - sqr(c.second);
    int sx21 = sqr(b.first) - sqr(a.first);
    int sy21 = sqr(b.second) - sqr(a.second);
    int test1 = 2 * ((y31) * (x12) - (y21) * (x13));
    int test2 = 2 * ((x31) * (y12) - (x21) * (y13));
    if(!test1 || !test2) return false;
    
    int f = (sx13 * x12 + sy13 * x12 + sx21 * x13 + sy21 * x13)/ test1;
    int g = (sx13 * y12 + sy13 * y12 + sx21 * y13 + sy21 * y13)/ test2;

    d = {-g, -f};
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


    while(1){
        int n; cin>>n;
        if(n==0) break;
		if(n==1){
			cout<<1<<endl;
			continue;
		} else if(n==2){
			cout<<2<<endl;
			continue;
		}
        vector<pair<int, int>> pontos(n);
        for(int i = 0; i<n; i++)
            cin>>pontos[i].first>>pontos[i].second;
		int maior = 2;
		pair<int, int> a, b, c, cent;
        for(int i = 0; i<n-2; i++){
			a = pontos[i];
			for(int j = i+1; j<n-1; j++){
				b = pontos[j];
				for(int k = j+1; k<n; k++){
					c = pontos[k];
					if(!center(a, b, c, cent)) continue;
					unordered_map<double, int> mp;
					if(maior<3) maior = 3;
					for(int m = 0; m<n; m++){
						if(m==i || m==j || m==k) continue;
						double d = distpow(pontos[m], cent);
						if(mp.find(d)!=mp.end()){
							mp[d]++;
							if(mp[d]>maior) maior = mp[d];
						}
						else mp[d]=1;
					}
				}
			}
		}
		cout<<maior<<endl;
        
    }
 
    return 0;
}