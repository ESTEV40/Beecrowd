#include <bits/stdc++.h>

using namespace std;
//infelizmente dá TIME LIMITE EXCEEDED
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;

    while(cin >> N && cin >> D && (N != 0 && D != 0)){

        string quadro;
        string resposta;
        cin >> quadro;

        int Delete = D;
        int Ind_inicio = 0, Ind_Maior;

        while (Delete > 0 && resposta.length() < (N - D)) {
            char maior = quadro[Ind_inicio];
            Ind_Maior = Ind_inicio;

            for (int i = Ind_inicio + 1; i <= Ind_inicio + Delete; i++) {
                if (quadro[i] > maior) {
                    maior = quadro[i];
                    Ind_Maior = i;
                }
            }

            resposta += quadro[Ind_Maior];
            Delete -= (Ind_Maior - Ind_inicio);
            Ind_inicio = Ind_Maior + 1;
        }

        if(Ind_Maior < quadro.length() && resposta.length() < (N-D))
            resposta += quadro.substr(Ind_Maior+1, (quadro.length() - Ind_Maior));

        cout << resposta << endl;
    }
    return 0;
}