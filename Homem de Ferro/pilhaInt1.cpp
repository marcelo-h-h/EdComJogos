#include <iostream>

#include "pilhaInt1.h"

template<class TDA>
bool PilhaInt1<TDA>::Empilha(const TDA &elemento_x){
        TDA aux;
        Pilha<TDA>::Desempilha(aux);
        Pilha<TDA>::Empilha(aux);

        if(aux.getCorVermelha()!= elemento_x.getCorVermelha() && (aux.getValor() == elemento_x.getValor()-1          ||
                                                                  elemento_x.getPropriedadeEspecial())                )
        {
            Pilha<TDA>::Empilha(elemento_x);
            return true;
        }
        else{
            return false;
        }
}
