#include <iostream>

#ifndef pilhaBurra
#define pilhaBurra

#define tamanho 21

template<class TDA>
class Pilha{

    private:
        int topo;
        TDA elementos[tamanho];

    public:
        Pilha();

        bool Empilha(const TDA &elemento_x);
        bool Desempilha(TDA &elemento_x);
        bool Vazia() const;
        bool Cheia() const;

        TDA getTopo() const; /* esse método é só pra teste. Teoricamente, ele não deve existir haha */
        void print() const;
};

#endif // pilhaBurra
