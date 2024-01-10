#include <bits/stdc++.h>
#define LC_TAB 8

using namespace std;

class posicao_tab{

    public :

        bool visitado;
        bool terminado;
        posicao_tab* pai;
        int distancia;

    public :
        posicao_tab(){
            this->visitado = false;
            this->terminado = false;
            this->pai = nullptr;
            this->distancia = -1;
        }
};

vector<pair<int, int>> adjacentes(int lin, int col){

    vector<pair<int,int>> coord_pos;

    //no Tabuleiro: dois da diagonal superior direita
    if((lin+2 >= 0 && lin+2 < LC_TAB) && (col+1 >= 0 && col+1 < LC_TAB)){
        coord_pos.push_back(make_pair(lin+2,col+1));
    }
    if((lin+1 >= 0 && lin+1 < LC_TAB) && (col+2 >= 0 && col+2 < LC_TAB)){
        coord_pos.push_back(make_pair(lin+1,col+2));
    }

    //no Tabuleiro: dois da diagonal inferior direita
    if((lin-1 >= 0 && lin-1 < LC_TAB) && (col+2 >= 0 && col+2 < LC_TAB)){
        coord_pos.push_back(make_pair(lin-1,col+2));
    }
    if((lin-2 >= 0 && lin-2 < LC_TAB) && (col+1 >= 0 && col+1 < LC_TAB)){
        coord_pos.push_back(make_pair(lin-2,col+1));
    }

    //no Tabuleiro: dois da diagonal inferior esquerda
    if((lin-1 >= 0 && lin-1 < LC_TAB) && (col-2 >= 0 && col-2 < LC_TAB)){
        coord_pos.push_back(make_pair(lin-1,col-2));
    }
    if((lin-2 >= 0 && lin-2 < LC_TAB) && (col-1 >= 0 && col-1 < LC_TAB)){
        coord_pos.push_back(make_pair(lin-2,col-1));
    }

    //no Tabuleiro: dois da diagonal superior esquerda
    if((lin+1 >= 0 && lin+1 < LC_TAB) && (col-2 >= 0 && col-2 < LC_TAB)){
        coord_pos.push_back(make_pair(lin+1,col-2));
    }
    if((lin+2 >= 0 && lin+2 < LC_TAB) && (col-1 >= 0 && col-1 < LC_TAB)){
        coord_pos.push_back(make_pair(lin+2,col-1));
    }
    return coord_pos;
}

int distancia(posicao_tab* p){
    int d = 0;
    while(p != nullptr){
        p = p->pai;
        d++;
    }
    return d;
}

int BFS_TABLE(pair<int, int> origem, pair<int,int> destino){

    vector<vector<posicao_tab>> Knight(LC_TAB, vector<posicao_tab>(LC_TAB));

    queue<pair<int,int>> fila;

    Knight[origem.first][origem.second].distancia = 0;
    Knight[origem.first][origem.second].visitado = true;

    if(origem == destino)
        return 0;

    fila.push(origem);

    while(!fila.empty()){

        pair<int,int> atual = fila.front();
        fila.pop();
        vector<pair<int,int>> adj = adjacentes(atual.first, atual.second);

        for(pair<int,int> C: adj){

            if(!Knight[C.first][C.second].visitado){
                Knight[C.first][C.second].pai = &Knight[atual.first][atual.second];
                Knight[C.first][C.second].distancia = distancia(Knight[C.first][C.second].pai);
                Knight[C.first][C.second].visitado = true;

                if((C.first == destino.first) && (C.second == destino.second))
                   return Knight[C.first][C.second].distancia;

                fila.push(C);
            }
        }
        Knight[atual.first][atual.second].terminado = true;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char char_origem, char_destino;
    int int_origem, int_destino;
    while (cin >> char_origem >> int_origem >> char_destino >> int_destino) {

        pair<int, int> origem = make_pair(char_origem - 'a', int_origem - 1);
        pair<int, int> destino = make_pair(char_destino - 'a', int_destino - 1);

        int resultado = BFS_TABLE(origem, destino);

        cout << "To get from " << char_origem << int_origem << " to " << char_destino << int_destino << " takes " << resultado << " knight moves." << endl;
    }

    return 0;
}
