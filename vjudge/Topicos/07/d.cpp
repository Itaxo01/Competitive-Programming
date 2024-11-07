#include <bits/stdc++.h>
using namespace std;
int matriz[605][606][4]; // celula [i][j] com direcões 0: Norte, 1: Sul
							// 2: Leste, 3: Oeste (1 = liberado, 0 = bloqueado)
		

void dfs(int i, int j, vector<vector<bool>> &visitados){
	visitados[i][j] = true;

	for(int k = 0; k<4; k++){
		if(matriz[i][j][k]){ 
			if(k == 0 && !visitados[i-1][j]){
				dfs(i-1, j, visitados);
				break;
			}
			if(k == 1 && !visitados[i+1][j]){
				dfs(i+1, j, visitados);
				break;
			}
			if(k == 2 && !visitados[i][j+1]){
				dfs(i, j+1, visitados);
				break;
			}
			if(k == 3 && !visitados[i][j-1]){
				dfs(i, j-1, visitados);
				break;
			}
		}
	}
}

void printMatrix(int rows, int cols) {
    cout << " ";
    for (int j = 0; j < cols; ++j) {
        cout << (matriz[0][j][0] == 0 ? "_" : " ");
        cout << " ";
    }
    cout << endl;

    for (int i = 0; i < rows; ++i) {
        cout << (matriz[i][0][3] == 0 ? "|" : " ");
        for (int j = 0; j < cols; ++j) {
            cout << (matriz[i][j][1] == 0 ? "_" : " ");
            if (j == cols - 1) {
                cout << (matriz[i][j][2] == 0 ? "|" : " ");
            } else {
                cout << (matriz[i][j + 1][3] == 0 ? "|" : " ");
            }
        }
        cout << endl;
    }
}

int main(){
	int a; 
	while(cin>>a){

		for(int i = 0; i<2*a; i++){
			for(int j = 0; j<(2*a+1); j++){
				for(int k = 0; k<4; k++){
					matriz[i][j][k] = 1;
				}
				if(i == 0) matriz[i][j][0] = 0;
				if(i == (2*a-1)) matriz[i][j][1] = 0;
				if(j == 0) matriz[i][j][3] = 0;
				if(j == (2*a)) matriz[i][j][2] = 0;
			}
		}
		for(int i = 1; i<=(2*a-1); i++){
			string s; cin>>s;
			if(i & 1){
				int j = 1;
				for(char e: s){
					if(e == 'H'){
						matriz[i-1][j-1][1] = 0;
						matriz[i-1][j][1] = 0;
						matriz[i][j-1][0] = 0;
						matriz[i][j][0] = 0;
					} else{
						matriz[i-1][j-1][2] = 0;
						matriz[i-1][j][3] = 0;
						matriz[i][j-1][2] = 0;
						matriz[i][j][3] = 0;
					}
					j+=2;
				}
			}else{
				int j = 2;
				for(char e: s){
					if(e == 'H'){
						matriz[i-1][j-1][1] = 0;
						matriz[i-1][j][1] = 0;
						matriz[i][j-1][0] = 0;
						matriz[i][j][0] = 0;
					} else{
						matriz[i-1][j-1][2] = 0;
						matriz[i-1][j][3] = 0;
						matriz[i][j-1][2] = 0;
						matriz[i][j][3] = 0;
					}
					j+=2;
				}
			}
		}
		
		// printMatrix(2*a, 2*a+1);

		
		vector<vector<bool>> visitados(2*a, vector<bool>(2*a+1, false));
		int count = 0;
		for(int i = 0; i<2*a; i++){
			for(int j = 0; j<(2*a+1); j++){
				if(!visitados[i][j]){
					dfs(i, j, visitados);
					if(j || i) count++;
				}
			}
		}
		cout<<count<<endl;
	}
}