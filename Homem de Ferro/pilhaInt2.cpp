#include <iostream>
#include "pilhaInt2.h"

template<class TDA>
bool PilhaInt2<TDA>::Empilha(const TDA &elemento_x){
        TDA aux;
        Pilha<TDA>::Desempilha(aux);
        Pilha<TDA>::Empilha(aux);

        if(aux.getNaipe()   == elemento_x.getNaipe() &&
           aux.getValor()+1 == elemento_x.getValor()  )
        {
            Pilha<TDA>::Empilha(elemento_x);
            return true;
        }
        else
            return false;
}

