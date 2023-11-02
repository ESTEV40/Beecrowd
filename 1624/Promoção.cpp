#include <bits/stdc++.h>

using namespace std;

typedef struct produto{
    int preco;
    int peso;
}Tproduto;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Peso_Max;

    while(cin >> N && N!=0){

        vector<Tproduto> Matriz(N);
        for(int i = 0; i < N; i++){
            cin >> Matriz[i].preco >> Matriz[i].peso;
        }
        cin >> Peso_Max;

        vector<vector<int>> Bag(N + 1, vector<int>(Peso_Max + 1));

        for(int p  = 0; p < N+1;p++){
            Bag[p][0] = 0;
        }
        for(int q = 0; q < Peso_Max+1; q++){
            Bag[0][q] = 0; 
        }

        for(int i = 1; i < N + 1; i++){
            for(int j = 1; j < Peso_Max + 1; j++){
                if(Matriz[i-1].peso > j)
                    Bag[i][j] = Bag[i-1][j];
                else if((Bag[i - 1][j - Matriz[i - 1].peso] + Matriz[i - 1].preco) > (Bag[i - 1][j])){
                    Bag[i][j] = Bag[i - 1][j - Matriz[i - 1].peso] + Matriz[i - 1].preco;
                }else Bag[i][j] = Bag[i-1][j];
            }
        }
        cout << Bag[N][Peso_Max] << endl;


    }
    return 0;
}
