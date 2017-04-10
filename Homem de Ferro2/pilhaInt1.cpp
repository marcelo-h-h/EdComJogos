#include <iostream>

#include "pilhaInt1.h"

template<class TDA>
bool PilhaInt1<TDA>::Empilha(PilhaInt1<TDA> &pilha_x){
        TDA aux;
        Pilha<TDA>::Desempilha(aux);
        Pilha<TDA>::Empilha(aux);

        TDA aux2;
        pilha_x.Pilha<TDA>::Desempilha(aux2);

        if(aux.getCorVermelha()!= aux2.getCorVermelha() && (aux.getValor() == aux2.getValor()-1          ||
                                                                  aux2.getPropriedadeEspecial())         &&
           !Pilha<TDA>::Cheia()){

            Pilha<TDA>::Empilha(aux2);
            return true;
        }
        else{
            pilha_x.Pilha<TDA>::Empilha(aux2);
            return false;
        }
}
