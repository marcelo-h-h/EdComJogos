#include <iostream>
#include "card.h"

int Card::ultimoNaipe = 1;
int Card::ultimoValor = 1;

Card::Card(){
    naipe = ultimoNaipe;
    valor = ultimoValor;
    propriedadeEspecial = false;

    ultimoValor++;

    if(valor==13){
        ultimoNaipe++;
        ultimoValor = 1;
    }
    if(naipe%2!=0)
        corVermelha = false;
    else
        corVermelha = true;

    if(naipe>4){
        propriedadeEspecial = true;
        valor = 0;
        ultimoNaipe++;
    }
}

int Card::getNaipe() const{
    return naipe;
}

int Card::getValor() const{
    return valor;
}

bool Card::getCorVermelha() const{
    return corVermelha;
}

void Card::setNaipe(const int &_naipe){
    naipe = _naipe;
}

void Card::setValor(const int &_valor){
    valor = _valor;
}

void Card::setCorVermelha(const bool &_corVermelha){
    corVermelha = _corVermelha;
}

void Card::setPropriedadeEspecial(const bool &_propriedadeEspecial){
    propriedadeEspecial = _propriedadeEspecial;
}

bool Card::getPropriedadeEspecial() const{
    return propriedadeEspecial;
}

ostream& operator<<(ostream &output, const Card &elemento_x){

    output << elemento_x.naipe << "\t" << elemento_x.valor << "\t" << elemento_x.corVermelha;

    return output;
}
