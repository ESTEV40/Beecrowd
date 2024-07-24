#include <bits/stdc++.h>

using namespace std;

int main(){

    string Entrada;

    while(cin>>Entrada){

        if(Entrada == "OXX" || Entrada == "XXO") cout << "Alice" << endl;
        else if(Entrada == "XOX") cout << "*" << endl;
        else cout << "?" << endl;
    }

}