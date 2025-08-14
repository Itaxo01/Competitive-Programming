#include <bits/stdc++.h>
#define no {cout<<"N"<<endl; return 0;}
#define yes {cout<<"Y"<<endl; return 0;}
#define int long long
#define pii pair<int, int>
using namespace std;

vector<vector<pair<pii, pii>>> best; // melhor [l - r] e segundo melhor
int L, U;
int n, t;

signed main(){
	cin>>n>>t;
	vector<vector<int>> m(n, vector<int>(t));
	vector<vector<int>> prefix_m(n, vector<int>(t));
	best.assign(t, vector<pair<pii, pii>>(t, pair<pii, pii>({-1, -1}, {-1, -1})));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<t; j++){
			cin>>m[i][j];
			if(j) prefix_m[i][j] = m[i][j] + prefix_m[i][j-1];
			else prefix_m[i][j] = m[i][j];
		}
	}
	cin>>L>>U;
	for(int l = 0; l<t; l++){
		for(int r = l+L-1; r<l+U, r<t; r++){
			auto &[p1, p2] = best[l][r];
			for(int M = 0; M<n; M++){
				auto p = make_pair(prefix_m[M][r] - (l ? prefix_m[M][l-1] : 0), M+1);
				if(p > p1) {
					p2 = p1;
					p1 = p;
				} else if(p > p2){
					p2 = p;
				}
				// salvo para todo intervalo l r de tamanho maior igual que L e menor igual que U
				// quais as somas do intervalo de cada máquina
				// Com isso, posso determinar para uma certa posição do tempo qual a melhor
				// e a segunda melhor máquina, considerando um avanço de k unidades de tempo
			}
		}
	}
	vector<vector<int>> dp(t+120, vector<int>(n+1, -1)); // dp tempo maquina
	dp[0][0] = 0;
	for(int t1 = 1; t1<=t; t1++){
		for(int r = L+t1-1; r < U+t1 && r <= t; r++){
			for(int M = 0; M <= n; M++){
				if(dp[t1-1][M] != -1){
					auto &[p1, p2] = best[t1-1][r-1];
					if(p1.first != -1 && p1.second != M){
						int m_ = p1.second, s_ = p1.first;
						dp[r][m_] = max(dp[r][m_], dp[t1-1][M] + s_); 
					}
					if(p2.first != -1 && p2.second != M){
						int m_ = p2.second, s_ = p2.first;
						dp[r][m_] = max(dp[r][m_], dp[t1-1][M] + s_);
					}
				}
			}
		}
	}
	int maior = -1;

	for(int M = 1; M<=n; M++){
		maior = max(maior, dp[t][M]);
	}
	cout<<maior<<endl;
}