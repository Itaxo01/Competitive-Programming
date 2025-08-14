#include <bits/stdc++.h>
#define vc vector
using namespace std;

int l, c;
vc<vc<int>> visited;
void find(vc<vc<char>> &v, vc<int> &f, int i, int j, int ik, int jk, int N, vc<vc<bool>> &used){
	int p = 0;
	
	vc<int> fn(26);

	while(i >= 0 && i < l && j >= 0 && j < c && p < N){
		fn[v[i][j]-'A']++;
		i+=ik, j+=jk;
		p++;
	}
	for(int i = 0; i<26; i++){
		if(fn[i] != f[i]) return;
	}
	while(p--){
		i-=ik, j-=jk;
		used[i][j] = true;
	}
}

void find(vc<vc<char>> &v, string &s){
	int r = 0;
	vc<int> f(26);
	for(char c: s) f[c-'A']++;
	int N = s.size();
	vc<vc<bool>> used(l, vc<bool>(c, false));
	for(int i = 0; i<l; i++){
		for(int j = 0; j<c; j++){
			find(v, f, i, j, 0, 1, N, used);
			find(v, f, i, j, 1, 0, N, used);
			find(v, f, i, j, 1, 1, N, used);
			find(v, f, i, j, -1, 1, N, used);
		}
	}
	for(int i = 0; i<l; i++){
		for(int j = 0; j<c; j++){
			visited[i][j] += used[i][j];
		}
	}
}

int main(){
	cin>>l>>c;

	vc<vc<char>> v(l, vc<char>(c));
	visited.assign(l, vc<int>(c));
	for(int i = 0; i<l; i++){
		for(int j = 0; j<c; j++){
			cin>>v[i][j];
		}
	}
	int n; cin>>n;
	int res = 0;
	for(int i = 0; i<n; i++){
		string s; cin>>s;
		find(v, s);
	}
	for(int i = 0; i<l; i++){
		for(int j = 0; j<c; j++){
			res += (visited[i][j] >= 2);
		}
	}
	cout<<res<<endl;

	return 0;
}