#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct song{
    ll id,inicio, duracao, tipo;

    bool operator< ( song o) const {
        return inicio<o.inicio;
    }
};

int main(){
    int n;cin>>n;
    vector<song> songs;

    queue<song> normal;
    queue<song> priority;

    for(int i = 0;i<n;i++){
        int op;
        song s;cin>>s.inicio>>s.duracao>>op;
        s.id = i+1;
        s.tipo = op;
        songs.push_back(s);
    }
    sort(songs.begin(), songs.end());

    vector<int> infelizes;

    for(int i = 0;i<songs.size();i++){
        if (songs[i].tipo == 0)
            normal.push(songs[i]);
        else priority.push(songs[i]);
    }

    // for(int i = 0 ;i<n;i++){
    //     cout<<songs[i].id<<endl;
    // }

    song anterior = {-1,0,0,-1};
    song top;
    while(!priority.empty() && !normal.empty()){
        top = priority.front();
        // interrompe 
        if (top.inicio > anterior.inicio && top.inicio < anterior.inicio + anterior.duracao){
            infelizes.push_back(anterior.id);
            anterior = top;
            priority.pop();
        }else{
            // nao interrompe
            if (top.inicio == anterior.inicio + anterior.duracao){
                anterior = top;
                priority.pop();
            }else{
                normal.front().inicio = max(anterior.inicio + anterior.duracao, normal.front().inicio);
                anterior = normal.front(); normal.pop();
            }
        }
    }

    if (anterior.tipo==0 && !priority.empty()){
        if (top.inicio > anterior.inicio && top.inicio < anterior.inicio + anterior.duracao){
            infelizes.push_back(anterior.id);
        }
        anterior = top;
        priority.pop();
    }

    while(!priority.empty()){
        top = priority.front();
        if (top.inicio > anterior.inicio && top.inicio < anterior.inicio + anterior.duracao){
            infelizes.push_back(anterior.id);
        }
        anterior = top;
        priority.pop();
    }

    

    sort(infelizes.begin(), infelizes.end());
    cout<<infelizes.size()<<endl;
    if(infelizes.size()) cout<<infelizes[0];
    for(int i = 1 ;i<infelizes.size();i++){
        cout<<" "<<infelizes[i];
    }
    if(infelizes.size())cout<<endl;
}