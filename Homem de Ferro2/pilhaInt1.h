#include <iostream>

#ifndef pilhaInt1_h
#define pilhaInt1_h

#include "pilhaBurra.h"

template<class TDA>
class PilhaInt1 : public Pilha<TDA>{

    public:
        bool Empilha(PilhaInt1<TDA> &pilha_x);
};

#endif // pilhaInt1
