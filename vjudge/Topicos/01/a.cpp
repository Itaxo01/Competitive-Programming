#include <bits/stdc++.h>

using namespace std;
char M[41][41] = {'#'};
int visited[41][41];
int a, b;

bool checkValid(int i, int j);
bool baixo(int i, int j, string s);
bool lado(int i, int j, string s);
bool diagonal(int i, int j, string s);
bool diagonal2(int i, int j, string s);
void printa();

void visita(string s){
	int atual[41][41] = {0};
	for(int i = 0; i<a; i++){
		for(int j = 0; j<b; j++){
			if(s.find(M[i][j])!=-1){
				if(baixo(i, j, s)){
					for(int k = i; k<i+s.size(); k++){
						if(atual[k][j]==0) visited[k][j]++;
						atual[k][j]++;}}
				if(lado(i, j, s)){
					for(int k = j; k<j+s.size(); k++){
						if(atual[i][k]==0) visited[i][k]++;
						atual[i][k]++;}}
				if(diagonal(i, j, s)){
					for(int k = i, l = j; k<i+s.size(); k++, l++){
						if(atual[k][l]==0) visited[k][l]++;
						atual[k][l]++;}}
				if(diagonal2(i, j, s)){
					for(int k = i, l = j; k<i+s.size(); k++, l--){
						if(atual[k][l]==0) visited[k][l]++;
						atual[k][l]++;}}
				
			
			}
		}
	}	 
}

bool baixo(int i, int j, string s){
	vector<char> c;
	vector<char> s_v;
	for(char e:s) s_v.push_back(e); 
	for(int k = i; k<i+s.size(); k++){
		if(!checkValid(k, j)) return false;
		if(s.find(M[k][j])!=-1) c.push_back(M[k][j]);
		else return false;
	}
	sort(c.begin(), c.end());
	sort(s_v.begin(), s_v.end());
	if(c==s_v) return true;
	return false;
}
bool lado(int i, int j, string s){
	vector<char> c;
	vector<char> s_v;
	for(char e:s) s_v.push_back(e); 
	for(int k = j; k<j+s.size(); k++){
		if(!checkValid(i, k)) return false;
		if(s.find(M[i][k])!=-1) c.push_back(M[i][k]);
		else return false;
	}
	sort(c.begin(), c.end());
	sort(s_v.begin(), s_v.end());
	if(c==s_v) return true;
	return false;
}
bool diagonal(int i, int j, string s){
	vector<char> c;
	vector<char> s_v;
	for(char e:s) s_v.push_back(e); 
	for(int k = i, l = j; k<i+s.size() and l<j+s.size(); k++, l++){
		if(!checkValid(k, l)) return false;
		if(s.find(M[k][l])!=-1) c.push_back(M[k][l]);
		else return false;
	}
	sort(c.begin(), c.end());
	sort(s_v.begin(), s_v.end());
	if(c==s_v) return true;
	return false;
}

bool diagonal2(int i, int j, string s){
	vector<char> c;
	vector<char> s_v;
	for(char e:s) s_v.push_back(e); 
	for(int k = i, l = j; k<i+s.size() and l<j+s.size(); k++, l--){
		if(!checkValid(k, l)) return false;
		if(s.find(M[k][l])!=-1) c.push_back(M[k][l]);
		else return false;
	}
	sort(c.begin(), c.end());
	sort(s_v.begin(), s_v.end());
	if(c==s_v) return true;
	return false;
}

bool checkValid(int i, int j){
	if(i>=0 and i<a and j>=0 and j<b) return true;
	return false;
}

void printa(){
	int maior = 2;
	int count = 0;
	for(int i = 0; i<a; i++){
		for(int j = 0; j<b; j++){
			if(visited[i][j]>=maior) count++;
		}
	}
	cout<<count<<endl;
}
int main(){
	cin>>a>>b;
	for(int i = 0; i<a; i++){
		for(int j = 0; j<b; j++){
			char c; cin>>c;
			M[i][j] = c;
		}
	}
	int d; cin>>d;
	for(int i = 0; i<d; i++){
		string s; cin>>s;
		visita(s);
	}
	printa();

}