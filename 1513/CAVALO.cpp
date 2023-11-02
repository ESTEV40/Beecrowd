#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M,K;
    char **Tabu;

    while(cin >> N >> M >> K && N!=0 && M!=0 && K!=0 ){
        *Tabu = new char[N];
        for(int i=0 ; i < N ; i++){
            Tabu[i] = new char[M];
        }
        

    }

    return 0;
}