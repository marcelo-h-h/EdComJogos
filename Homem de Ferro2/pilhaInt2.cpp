#include <iostream>

#include "pilhaInt2.h"

template<class TDA>
bool PilhaInt2<TDA>::Empilha(PilhaInt2<TDA> &pilha_x){
        TDA aux;
        Pilha<TDA>::Desempilha(aux);
        Pilha<TDA>::Empilha(aux);

        TDA aux2;
        pilha_x.Desempilha(aux2);

        if(aux.getNaipe()   == aux2.getNaipe() &&
           aux.getValor()+1 == aux2.getValor()   ){
            Pilha<TDA>::Empilha(aux2);
            return true;
        }
        else{
            pilha_x.Empilha(aux2);
            return false;
        }
}
