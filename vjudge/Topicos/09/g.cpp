#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

bool coherent(vector<vector<int>> &v){
    for(int k = 0; k<v.size(); k++)
		for(int i = 0; i<v.size(); i++)
			for(int j = 0; j<v.size(); j++)
				if(v[i][k] + v[k][j] < v[i][j])
                    return false;
    return true;
}
int remove_direct(vector<vector<int>> &v){
    int count = 0;
    for(int k = 0; k<v.size(); k++)
		for(int i = 0; i<v.size(); i++)
			for(int j = 0; j<v.size(); j++)
				if(v[i][k] + v[k][j] == v[i][j] && i != j && k != i && k != j)
                    v[i][j] = INF, count++;
    return count;
}

int main(){
    int n; cin>>n;
    vector<vector<int>> v(n, vector<int>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>v[i][j];
        }
    }
    if(!coherent(v)){
        cout<<-1<<endl;
    } else{
        cout<<remove_direct(v)/2<<endl;
    }
}