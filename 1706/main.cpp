#include <bits/stdc++.h>

//incompleto
using namespace std;

typedef struct Torre{
    char valor;
    bool visitado;
    Torre *pai;
}Ttorre;

char inverte(char valor){
    return valor == 'A' ? 'B' : 'A';
}

char DFS(Ttorre Torre){
    if(Torre.valor == 'B')
        Torre.valor = inverte(Torre.valor);
        
    
}

int main(){

    int N, M, a, b;

    while(cin >> N >> M){

    if(Torre.valor == 'B')
        Torre.valor
        Ttorre Torres[N];

        for(int i = 0; i < N; i ++){
            cin >> Torres[i].valor;
            Torres[i].visitado = false;
        }
        for(int i = 0; i < M; i++){
            cin >> a >> b;
            Torres[a].próximo = &Torres[b];
            Torres[b].pai = &Torres[a];
        }


        cout << DFS(Torres);

    }
}