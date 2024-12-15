#include <bits/stdc++.h>
using namespace std;

void rearange(string &s, int pos, int k){
	int c = s[pos] - '0';
	c -= (pos - k);
	for(int i = pos; i > k; i--){
		s[i] = s[i-1];
	}
	s[k] = c + '0';
}

void work(){
	string s; cin>>s;
	for(int i = 0; i < s.size(); i++){
		int maior_pos = i;
		int maior = s[i] - '0';
		int dec = 1;
		for(int k = i+1; k <= min((int)s.size()-1, i+9); k++){
			if(s[k] - '0' - dec > maior){
				maior = (s[k] - '0') - dec;
				maior_pos = k;
			}
			dec++;
		}
		rearange(s, maior_pos, i);
	}
	cout<<s<<endl;
}

signed main(){
	int tt; cin>>tt;
	while(tt--){
		work();
	}
}