#include <iostream>
#include <cstdlib>
#include <ctime>

#include "card.h"
#include "pilhaBurra.cpp"
#include "pilhaInt1.cpp"
#include "pilhaInt2.cpp"

using namespace std;

int main(){

    srand(time(NULL));

    Card card[56];

    for(int i=0; i<52; i++){
        int posicaoAleatoria = rand() % 52;

        Card cardAuxiliar = card[i];
        card[i] = card[posicaoAleatoria];
        card[posicaoAleatoria] = cardAuxiliar;
    }

    PilhaInt1<Card> Pilha[8];
    int m = 0;
    int n = 7;

    for(int i=0; i<8; i++){
        for(int j=m; j<n; j++){
            Pilha[i].Pilha<Card>::Empilha(card[j]);
        }
        if(i<3){
            m = n;
            n+=7;
        }
        else{
            m = n;
            n+=6;
        }
    }

    for(int i=0; i<=3; i++){
        Pilha[4+i].Pilha<Card>::Empilha(card[52+i]);
    }

    for(int i=0; i<8; i++){
            Pilha[i].print();
            cout << "\n\n";
    }

    Pilha[1].Empilha(Pilha[2]);

    cout << Pilha[1].getTopo() << endl;

    Pilha[1].Empilha(Pilha[7]);

    cout << Pilha[1].getTopo() << "\n" << Pilha[7].getTopo() << endl;


    return 0;

}
