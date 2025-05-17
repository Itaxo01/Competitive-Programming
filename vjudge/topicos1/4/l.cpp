#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;

void place(int pos_i, int pos_j, int h, int l, int id){
	for(int i = pos_i; i<pos_i+h; i++){
		for(int j = pos_j; j<pos_j+l; j++){
			res[i][j] = id;
		}
	}
}

void print_res(){
	int n = res[0].size();
	for(int i = 0; i<res.size(); i++){
		for(int j = 0; j<n; j++){
			if(j) cout<<" ";
			cout<<res[i][j];
		} cout<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k, n; cin>>k>>n;
	res.assign(3, vector<int>(n));
	vector<int> v(k);
	for(int i = 0; i<k; i++){
		cin>>v[i];
	}
	int pos = 0;
	vector<int> x11, x21, x31, x22;
	for(int i = 0; i<k; i++){
		int l; cin>>l;
		int maior = max(l, v[i]), menor = min(l, v[i]);
		if(maior == 3 && menor >= 2){
			place(0, pos, maior, menor, i+1);
			pos+=menor;
		} else if(maior == 3) x31.push_back(i+1);
		else if(maior == 1) x11.push_back(i+1);
		else if(menor == 2) x22.push_back(i+1);
		else x21.push_back(i+1);
	}
	int match = min(x22.size(), x21.size());
	for(int i = 0; i<match; i++){
		place(0, pos, 1, 2, x21.back()); x21.pop_back();
		place(1, pos, 2, 2, x22.back()); x22.pop_back();
		pos += 2;
	}

	match = min(x22.size()/3, x31.size()/2);
	for(int i = 0; i<match; i++){
		place(1, pos, 2, 2, x22.back()); x22.pop_back();
		place(1, pos+2, 2, 2, x22.back()); x22.pop_back();
		place(1, pos+4, 2, 2, x22.back()); x22.pop_back();

		place(0, pos, 1, 3, x31.back()); x31.pop_back();
		place(0, pos+3, 1, 3, x31.back()); x31.pop_back();
		pos += 6;
	}
	match = min(x22.size(), x11.size()/2);
	for(int i = 0; i<match; i++){
		place(1, pos, 2, 2, x22.back()); x22.pop_back();
		place(0, pos, 1, 1, x11.back()); x11.pop_back();
		place(0, pos+1, 1, 1, x11.back()); x11.pop_back();
		pos += 2;
	}
	// Aqui a principio acabaram os 2x2 de certeza.
	while(!x31.empty()){
		place(0, pos, 3, 1, x31.back()); x31.pop_back();
		pos+=1;
	}
	while(x21.size() > 2){
		place(0, pos, 1, 2, x21.back()); x21.pop_back();
		place(1, pos, 2, 1, x21.back()); x21.pop_back();
		place(1, pos, 2, 1, x21.back()); x21.pop_back();
		pos+=2;
	}
	while(!x21.empty()){
		place(0, pos, 1, 1, x11.back()); x11.pop_back();
		place(1, pos, 2, 1, x21.back()); x21.pop_back();
		pos+=1;
	}
	while(!x11.empty()){
		place(0, pos, 1, 1, x11.back()); x11.pop_back();
		place(1, pos, 1, 1, x11.back()); x11.pop_back();
		place(2, pos, 1, 1, x11.back()); x11.pop_back();
		pos+=1;
	}
	print_res();
}