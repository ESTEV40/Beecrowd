// código em conserto, está dando runtime error


#include <bits/stdc++.h>
#define TAM_CANAL 100000

using namespace std;

class Canal_Clotilde{
    public :
        bool visitado;
        bool terminado;
        int distancia;
};

vector<int> canais_filhos(int atual, Canal_Clotilde channel[]){
    vector<int> filhos;

    if(atual-1 >= 1 && atual-1 != 0 && !channel[atual-1].visitado)
        filhos.push_back(atual-1);

    if(atual+1 < TAM_CANAL && !channel[atual+1].visitado)
        filhos.push_back(atual+1);

    if(atual <= 50000 && !channel[atual*2].visitado)
        filhos.push_back(atual*2);

    if(atual < 33334 && !channel[atual*3].visitado)
        filhos.push_back(atual*3);

    if((atual%2 == 0) && atual/2 != 0  && !channel[atual/2].visitado)
        filhos.push_back(atual/2);

    return filhos;
}

int BFS_Canal(int origem, int destino, Canal_Clotilde channel[]){
    if(origem == destino)
        return 0;

    queue<int> fila;

    channel[origem].distancia = 0;
    channel[origem].visitado = true;

    fila.push(origem);

    while(!fila.empty()){
        int atual = fila.front();
        fila.pop();

        vector<int> filhos = canais_filhos(atual, channel);
        for(int c : filhos){
            if(!channel[c].visitado && !channel[c].terminado){
                channel[c].visitado = true;
                channel[c].distancia = channel[atual].distancia + 1;

                if(c == destino) return channel[c].distancia;

                fila.push(c);
            }
        }
        channel[atual].terminado = true;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int O, D, K;

    while(cin >> O >> D >> K && O > 0 && D > 0 && K >= 0){
        Canal_Clotilde channel[TAM_CANAL] = {};


        for(int i = 1; i < TAM_CANAL; i++) {
            channel[i].visitado = false;
            channel[i].terminado = false;
            channel[i].distancia = 0; // Ou algum valor que indique não visitado
        }

        for(int i = 1 ;i < K; i++){
            int a;
            cin >> a;
            channel[a].visitado = true;      
        }

        cout << BFS_Canal(O, D, channel) << endl;
    }
}
