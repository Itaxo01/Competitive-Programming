#include <bits/stdc++.h>

using namespace std;

int size_a, size_b;

bool check(string a, char &c){
	for(int i = 0; i<a.size()-1; i++){
		if(a[i]!=a[i+1]) return false;
	}
	c = a[0];
	return true;
}

void divide(int a, int b, string s, string &res){
	int a1 = (a+1)/2, a2 = a/2;
	int b1 = (b+1)/2, b2 = b/2;
	pair<string, pair<int, int>> NW = {"", {a1, b1}};
	pair<string, pair<int, int>> NE = {"", {a1, b2}};
	pair<string, pair<int, int>> SW = {"", {a2, b1}};
	pair<string, pair<int, int>> SE = {"", {a2, b2}};
	for(int i = 0; i<a; i++){
		for(int j = 0; j<b; j++){
			if(i<a1){
				if(j<b1) NW.first.push_back(s[i*b+j]);
				else NE.first.push_back(s[i*b+j]);
			}
			else{
				if(j<b1) SW.first.push_back(s[i*b+j]);
				else SE.first.push_back(s[i*b+j]);
			}
		}
	}

	pair<string, pair<int, int>> directions[] = {NW, NE, SW, SE};
	char c = ' ';
	for(auto e:directions){
		if(e.first.size()>0){
			if(check(e.first, c)){
				res += c;
			}else{
				res +="D";
				divide(e.second.first, e.second.second, e.first, res);
			}
		}
	}

	 
}

void solve_D(int a, int b, string s, string &res){
	char c = ' ';
	if(check(s, c)){
		res += c;
		return;
	}else{
		res +="D";
		divide(a, b, s, res);
	}
}

void expand(int a, int b, int pos_j, int pos_i, char c, string &res){
	for(int i = pos_i; i<pos_i+b; i++){
		for(int j = pos_j; j<pos_j+a; j++){
			res[i*size_b+j] = '1';
		}
	}
}

void solve_B(int a, int b, int pos_j, int pos_i, int &pos, string s, string &res){
	char c = s[pos];
	if(c != 'D'){
		if(c == '1') expand(a, b, pos_j, pos_i, c, res);
		pos++;
	}else{
		int a1 = (a+1)/2, a2 = a/2;
		int b1 = (b+1)/2, b2 = b/2;
		pair<pair<int, int>, pair<int, int>> NW = {{a1, b1}, {pos_j, pos_i}};
		pair<pair<int, int>, pair<int, int>> NE = {{a2, b1}, {pos_j+a1 , pos_i}};
		pair<pair<int, int>, pair<int, int>> SW = {{a1, b2}, {pos_j, pos_i+b1}};
		pair<pair<int, int>, pair<int, int>> SE = {{a2, b2}, {pos_j+a1 , pos_i+b1}};
		pair<pair<int, int>, pair<int, int>> directions[] = {NW, NE, SW, SE};
		pos++;
		for(auto e:directions){
			if(e.first.first and e.first.second) solve_B(e.first.first, e.first.second,
			e.second.first, e.second.second, pos, s, res);
		}
	}
	return;
}

int main(){
	while(true){	
		char c; cin>>c;
		if(c=='#') break;
		cin>>size_a>>size_b;
		string res = "";
		if(c=='B'){
			string s(size_a*size_b, ' ');
			for(int i = 0; i<size_a*size_b; i++){
				cin>>s[i];
			}
			solve_D(size_a, size_b, s, res);
			printf("%c%4d%4d\n", 'D', size_a, size_b);
		}
		else if(c=='D'){
			string s; cin>>s;
			int pos = 0;
			for(int i = 0; i<size_a*size_b; i++) res+='0';
			solve_B(size_b, size_a, 0, 0, pos, s, res);
			printf("%c%4d%4d\n", 'B', size_a, size_b);
		}
		int counter = 0;
		while(res.size()-counter>50){
			cout<<res.substr(counter, 50)<<endl;
			counter+=50;
		}
		cout<<res.substr(counter, res.size()-counter)<<endl;
	}
}