#include <bits/stdc++.h>

using namespace std;
int main(){
	string order = "SHDC";
	while(true){
		int a, b, c; cin>>a>>b>>c;
		if(a==0) break;
		
		auto cmp = [](pair<int, char> a, pair<int, char> b) {
        if (a.first == b.first) {
            // Custom order for the chars
            string order = "SHDC";
            return order.find(a.second) < order.find(b.second);
        }
        return a.first > b.first; // Sort int in descending order
	    };

		vector<multiset<pair<int, char>, decltype(cmp)>> cartas_jogador(a, multiset<pair<int, char>, decltype(cmp)>(cmp));
		 queue<pair<int, char>> banco;
		stack<pair<int, char>> lixo;
		int proximo = 0; //próximo jogador
		int sentido = 1; //+1 = horário, -1 = antihorário
		int id = -1;
		bool primeira = true;
		for(int i = 0; i<c; i++){
			if(i%b == 0) id++;
			int num; char nipe; cin>>num>>nipe;
			if(id<a) cartas_jogador[id].insert({num, nipe});
			else{
				if(primeira){
					primeira = false;
					lixo.push({num, nipe});
					if(num == 12) sentido*=-1;
					}
				else banco.push({num, nipe});
		    }
		}
		bool pescou = false;
		while(true){
			int player = proximo;
			pair<int, char> carta_atual = lixo.top();
			char naipe = carta_atual.second;
			int numero = carta_atual.first;

			if(numero == 7 and !pescou){
				pair<int, char> c1, c2;
				c1 = banco.front(); banco.pop();
				c2 = banco.front(); banco.pop();
				cartas_jogador[player].insert(c1);
				cartas_jogador[player].insert(c2);
				pescou = true;
			}
			else if(numero == 1 and !pescou){
				pair<int, char> c1 = banco.front(); banco.pop();
				cartas_jogador[player].insert(c1);
				pescou = true;
			}
			else if(numero == 11 and !pescou){
				pescou = true;
			}
			else{
				pescou = false;
				bool achou1 = false, achou2 = false;
				pair<int, char> carta1 = {-1, ' '};
				pair<int, char> carta2 = {-1, ' '};
				multiset<pair<int, char>, decltype(cmp)>::iterator card1, card2;
				for(char e: order){
					card1 = cartas_jogador[player].find({numero, e});
					if(card1!=cartas_jogador[player].end()){
						carta1 = *card1;
						achou1 = true;
						break;
					}
				}
				for(int i = 13; i>0; i--){
					card2 = cartas_jogador[player].find({i, naipe});
					if(card2!=cartas_jogador[player].end()){
						carta2 = *card2;
						achou2 = true;
						break;
					}
				}
				if(achou1 and achou2){
					if(!cmp(carta1, carta2)){
						lixo.push(carta2);
						cartas_jogador[player].erase(card2);
						if(carta2.first == 12){
							sentido *= -1;
						}	
					}
					else{
						lixo.push(carta1);
						cartas_jogador[player].erase(card1);
						if(carta1.first == 12){
							sentido *= -1;
						}
					}
				}
				else if(achou1){
					lixo.push(carta1);
						cartas_jogador[player].erase(card1);
						if(carta1.first == 12){
							sentido *= -1;
						}
				}
				else if(achou2){
					lixo.push(carta2);
						cartas_jogador[player].erase(card2);
						if(carta2.first == 12){
							sentido *= -1;
						}
				}
				else{
					carta1 = banco.front(); banco.pop();
					if(carta1.first == numero || carta1.second == naipe){
					    lixo.push(carta1);
					    if(carta1.first == 12) sentido*=-1;}
					else{
					    cartas_jogador[player].insert(carta1);
				        pescou = true;
					}
				}
			}
			if(cartas_jogador[player].empty()){
			    cout<<player+1<<endl; break;}
			proximo = (proximo+sentido+a)%a;
		}
	}
}