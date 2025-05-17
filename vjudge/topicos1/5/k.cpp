#include <bits/stdc++.h>
using namespace std;
#define check(b) (b == '1' ? true : false)

string s;
int k;
void modify(int pos, int mod, int seg){
	int count = 1;
	int m_aux = 0;
	for(int i = pos+1; i < pos+seg-1; i++){
		count++;
		if(count == k){
			s[i] = (s[i] == '0' ? '1' : '0');
			count = 0;
			m_aux++;
		}
	}
	int i = pos+seg-2;
	while(m_aux < mod){
		s[i] = (s[i] == '0' ? '1' : '0');
		m_aux++;
		i--;
	}
}

int main(){
	cin>>k>>s;
	int res = 0;
	char b = s[0];
	int count = 1;
	if(k == 2){
		int c1 = 0, c2 = 0;
		bool c = true;
		for(int i = 0; i<s.size(); i++){
			if(c == check(s[i])) c2++;
			else c1++;
			c = !c;
		}
		res = min(c1, c2);
		if(c1 < c2){
			for(int i = 0; i<s.size(); i++){
				if(i % 2 == 0) s[i] = '1';
				else s[i] = '0';
			}
		} else {
			for(int i = 0; i<s.size(); i++){
				if(i % 2 == 0) s[i] = '0';
				else s[i] = '1';
			}
		}
	} else {
		vector<pair<int, int>> segmentos;
		for(int i = 1; i<s.size(); i++){
			if(s[i] == b)
			count++;
			else {
				segmentos.push_back({count, b-'0'});
				count = 1;
				b = s[i];
			}
		}
		segmentos.push_back({count, b-'0'});
		int pos = 0;
		for(int i = 0; i<segmentos.size(); i++){
			auto e = segmentos[i];
			if(e.first >= k){
				int mod = e.first/k;
				res += mod;
				modify(pos, mod, e.first);
			}
			pos+=e.first;
		}
	}
	cout<<res<<" "<<s<<endl;
}