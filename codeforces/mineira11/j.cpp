#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b; cin>>a>>b;
    vector<bool> v(1000, false);
    int res = 0;
    vector<int> sobraram;
    for(int i = 0; i<a; i++){
        int c; cin>>c;
        int pos = c+b; // turno em que c == d subindo.
        if(c < b){
            // se c < b, a unica chance de ele ser comido é na subida
            // nessa primeira etapa apenas verifico a disponibilidade da subida
            // dessa forma, se estiver vago ele será comido
            if(!v[pos]){
                v[pos] = true;
                res++;
            }
        } else {
            if(!v[pos]){ // verifica se o turno da sua subida está vago
                        // não é para ter conflito com os que começam subindo
                v[pos] = true;
                res++;
            } else {
                sobraram.push_back(c); // Os que sobram são os que possivelmente
                                        // serão comidos na descida
            }
        }
    }
    for(int e:sobraram){ // os unicos que podem entrar aqui são os c >= b
        int pos = e-b;
        if(!v[pos]){
            v[pos] = true;
            res++;
        }
    }
    cout<<res<<endl;

}