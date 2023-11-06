#include <bits/stdc++.h>

using namespace std;

/*
    recursivamente também
    
    if (Noglo[j] > Quadro[i]) {
        // Noglo[j] can win against Quadro[i]. Recurse to the next elements.
        return 1 + ContBattles(Quadro, Noglo, i - 1, j - 1);
    } else {
        // Noglo[j] cannot win against Quadro[i]. Recurse only in Quadro.
        return ContBattles(Quadro, Noglo, i - 1, j);
    }

*/

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int Nsol;
    vector<int> Noglo;
    vector<int> Quadro;
    int a;

    while(cin >> Nsol){
        for(int i = 0; i < Nsol; i++){
            cin >> a;
            Quadro.push_back(a);
        }
        for(int i = 0; i < Nsol; i++){
            cin >> a;
            Noglo.push_back(a);
        }

        sort(begin(Quadro), end(Quadro));
        sort(begin(Noglo), end(Noglo));

        int contBattles = 0;

        for(int i = Nsol-1, j = Nsol-1; i >= 0; i--){
            if(Noglo[j] > Quadro[i]){
                contBattles++;
                j--;
            }
        }

        cout << contBattles << endl;
    }

    return 0;
}