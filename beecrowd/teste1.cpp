#include <bits/stdc++.h>

using namespace std;

int main(){
    int alvo; 
    while(cin >> alvo) {
    cout << "alvo" << alvo;
    int a[200];
    int t; cin >> t; cout << "t : " << t << endl;
    for (int i = 0 ; i < t; i++) {
        cin >> a[i];
        cout << a[i];
    }
    cout << endl;

    int limitBitmask = (1 << t);
    int ant = 0;
    int total = 0;
    int ans = 0;
    int menor  = 0;
    int iatual = 0;
    // gera todas as combinacoes
    int bmaskres = 0;
    int anterior = 0;
    for (int bmask = 0; bmask < limitBitmask; bmask++) {
        if (bmask > 0) {
            ant = total;
            cout <<"ant : " << total << endl;
        }
        total = 0;
        for (int j  = 0; j < t; j++) {
            if (bmask & (1 << j)) { 
                total += a[j];
            }
        }
        int difA = abs(alvo - ant);
        if(bmask == 0) menor = difA;
        int difB = abs(alvo - total);
        cout << difA << " difB " << difB << endl;

        if (abs(difA) < abs(difB)){
            if (abs(difA) < menor) {
                menor = abs(difA);
                ans = ant;
                bmaskres = bmask;
            }
            if (difA == menor){
                if (bmaskres < bmask){
                    cout << "+++((*(*aconteceu_+++" << endl; 

                    bmaskres = bmask;
                    ans = ant;
                    menor = abs(difA);
                }
            }
        }
         
        else{ 
            if (abs(difB) < menor){
                cout << "difb :" << difB << "é meno q menor :" << menor << endl;
                menor = abs(difB);
                ans = total;
                bmaskres = bmask;
            }
            if (difB == menor) {
                if (bmaskres < bmask){
                    cout << "+++((*(*aconteceu_+++" << endl; 
                    bmaskres = bmask;
                    ans = ant;
                    menor = abs(difA);
                }
            }
        }
        cout << "menor : " << menor << endl;
       cout << "ans : " << ans << endl; 
    }
    cout << "+++++++"<<endl;
    cout << "+++++++"<<endl;
    cout << "+++++++"<<endl;
    
    cout << bmaskres << endl;
    for (int j  = 0; j < t; j++) {
            if (bmaskres & (1 << j)) { 
                cout << a[j] << " ";
            }
        }
    cout <<"sum: " << ans << endl;
    }
    return 0;
}