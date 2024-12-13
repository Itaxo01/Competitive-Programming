#include <bits/stdc++.h>
#define INF 1e9
#define ii pair<int, int>
using namespace std;

bool isPossible(int a, int b, vector<vector<ii>> &v){
    vector<bool> visited(v.size(), false);
    int energy = 100;
    vector<int> chegaram_em_b;
    queue<ii> q;
    q.push({a, energy});
    visited[a] = true;
    int it = 0;
    int it_max = v.size();
    while(!q.empty()){
        int u = q.front().first, w = q.front().second; q.pop();
        if(u == b) {
            chegaram_em_b.push_back(w);
            it++;
        }
        for(auto e: v[u]){
            if(!visited[e.first] && w+e.second > 0){
                visited[e.first] = true;
                q.push({e.first, w+e.second});
            }
        }
    }
    for(int e: chegaram_em_b){
        if(e >= 0) return true;
    }
    return false;
}

bool isConnected(int a, int b, vector<vector<ii>> &v){
    vector<bool> visited(v.size(), false);
    queue<int> q;
    q.push(a);
    visited[a] = true;
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(u == b) return true;
        for(auto e: v[u]){
            if(!visited[e.first]){
                visited[e.first] = true;
                q.push(e.first);
            }
        }
    }
    return false;
}

int cicle = 0;

bool bellmmanford(vector<vector<ii>> &v){ // check if there is a positive cycle
	vector<int> dist(v.size(), -INF);
	dist[0] = 100;
	for(int i = 0; i<v.size(); i++){
		for(int u = 0; u<v.size(); u++)
			for(int j = 0; j<v[u].size(); j++){
				ii aux = v[u][j];
                if(dist[u] <= 0) continue;
				dist[aux.first] = max(dist[aux.first], dist[u] + aux.second);
    		}
	}

	for(int i = 0; i<v.size(); i++){
		for(int j = 0; j<v[i].size(); j++){
			ii aux = v[i][j];
			if(dist[aux.first] < dist[i]+aux.second){
                cicle = i;
				return true;
			}
		}
	}
	return false;
}



int main(){
    while(true){
        int n; cin>>n;
        if(n == -1) break;
        vector<vector<ii>> v(n);
        for(int i = 0; i<n; i++){
            int w, a; cin>>w>>a;
            for(int k = 0; k<a; k++){
                int b; cin>>b;
                v[i].push_back({b-1, w});
            }
        }
        if(isPossible(0, n-1, v)){
            cout<<"winnable"<<endl;
        } else{
            if(bellmmanford(v)){
                if(isPossible(0, cicle, v) && isConnected(cicle, n-1, v)) 
                    cout<<"winnable"<<endl;
                else cout<<"hopeless"<<endl;
            } else cout<<"hopeless"<<endl;
        }
    }
}