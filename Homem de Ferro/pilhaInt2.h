#include <iostream>

#ifndef pilhaInt2_h
#define pilhaInt2_h

#include "pilhaBurra.h"

template<class TDA>
class PilhaInt2 : public Pilha<TDA>{

    public:
        bool Empilha(const TDA &elemento_x);
};

#endif // pilhaInt2
