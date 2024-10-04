    #include<bits/stdc++.h>

    using namespace std;

    int nVertices, nEdges;
    vector<pair<int, int>> adj[1000000];
    int edges[1000000];
    int visited[1000000] = {0};

    int dfs(int u, int start){
        int passadas = 0;
        visited[u]++;

        for (pair<int, int> edge: adj[u]) {
            if (visited[edge.first] == start+1) continue; 
            int p = dfs(edge.first, start);
            edges[edge.second] += p;
            passadas += p;
        }

        if (u > start) {
            passadas++;
        }

        return passadas;
    }

    int main() {
        ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
        cin>>nVertices;
        nEdges = nVertices-1;

        memset(edges, 0, sizeof(edges));
        for (int i = 0; i < nEdges; i++) {
            int u, v; cin>>u>>v;
            u--; v--;
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }

        for (int i = 0; i < nVertices; i++) {
            dfs(i, i);
        }

        sort(edges, edges+nEdges);
        int previous = edges[0];
        
        int totalPassadas = 0;
        int totalEdges = 0;

        int atual = 0;  
        for (int i = 0; i < nEdges; i++) {
            if (edges[i] > totalPassadas) {
                totalPassadas = edges[i];
                totalEdges = 0;
            } 
            
            if (totalPassadas == edges[i]) {
                totalEdges++;
            }

            previous = edges[i];
        }   

        cout<<totalPassadas<<" "<<totalEdges<<endl;

        return 0;
    }