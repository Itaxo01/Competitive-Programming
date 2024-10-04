#include <bits/stdc++.h>

using namespace std;
pair<bool, int> pe(map<int, int> cards){
	for(int i = 10; i<=13; i++){
		if(cards[i]!=0) return {true, i};
	}
	return {false, -1};
}

pair<bool, int> pb(map<int, int> cards, int p, int g){
	for(int i = p; i<=g; i++){
		if(cards[i]!=0){
			return {true, i};
		}
	}
	return {false, -1};
}


int main(){
	int n; cin>>n;
	map<int, int> cards;
	for(int i = 1; i<=13; i++){
		cards[i] = 4;
	}
	int a, b, c, d; cin>>a>>b>>c>>d;
	cards[a]--; cards[b]--; cards[c]--; cards[d]--;
	int mary = min(d, 10)+min(c, 10);
	int john = min(a, 10)+min(b, 10);
	for(int i = 0; i<n; i++){
		int common; cin>>common;
		cards[common]--;
		mary+=min(10, common);
		john+=min(10, common);
	}
	int perde = 24-john;
	int ganha = 23-mary;
	
	if(perde>10 and ganha>10) cout<<-1<<endl;
	else if(ganha<=perde){
		if(ganha==10){
			if(pe(cards).first) cout<<pe(cards).second<<endl;
			else cout<<-1<<endl;
		}else{
			if(cards[ganha]!=0) cout<<ganha<<endl;
			else cout<<-1<<endl;}
	}else{
		if(perde==10){
			if(pe(cards).first) cout<<pe(cards).second<<endl;
			else cout<<-1<<endl;
		}
		else if(pb(cards, perde, ganha).first) cout<<pb(cards, perde, ganha).second<<endl;
		else cout<<-1<<endl;

	}
}