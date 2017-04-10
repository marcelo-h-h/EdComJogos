#include <iostream>
#include "pilhaBurra.h"

using std::cout;
using std::endl;

template <class TDA>
Pilha<TDA>::Pilha(){
    topo = -1;
}

template <class TDA>
bool Pilha<TDA>::Empilha(const TDA &elemento_x){
    if(Cheia())
        return false;
    else{
        topo+=1;
        elementos[topo] = elemento_x;
        return true;
    }
}

template <class TDA>
bool Pilha<TDA>::Desempilha(TDA &elemento_x){
    if(Vazia())
        return false;
    else{
        elemento_x = elementos[topo];
        topo-=1;
        return true;
    }
}

template <class TDA>
bool Pilha<TDA>::Vazia() const{
    if(topo == -1)
        return true;
    else
        return false;
}

template <class TDA>
bool Pilha<TDA>::Cheia() const{
    if(topo == tamanho-1)
        return true;
    else
        return false;
}

template <class TDA>
TDA Pilha<TDA>::getTopo() const{
    return elementos[topo];
}

template <class TDA>
void Pilha<TDA>::print() const{
    for(int i=0; i<=topo; i++){
        cout << elementos[i] << endl;
    }
}
