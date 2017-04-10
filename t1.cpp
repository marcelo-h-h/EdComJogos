/*MADE BY MARCELO ONLY*/
#include <iostream>
#include <ctime>
#include <cstdlib>

#define tamanho 21

using namespace std;

/*CLASSE CARTAS*/
class Card{

    friend ostream& operator<<(ostream&, const Card &elemento_x); // Pra imprimir no main usando um método
                                                                  // que só está para teste.
    private:
        int naipe;
        int valor;
        bool corVermelha;
        bool propriedadeEspecial;

        static int ultimoNaipe;
        static int ultimoValor;

    public:
        Card();

        void setNaipe(const int &_naipe);
        void setValor(const int &_valor);
        void setPropriedadeEspecial(const int &_propriedadeEspecial);
        void setCorVermelha(const bool &_corVermelha);

        int  getNaipe() const;
        int  getValor() const;
        bool getPropriedadeEspecial() const;
        bool getCorVermelha() const;
};

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
//As ultimas quatro cartas são especiais, duas não vermelhas e duas sim vermelhas
    if(ultimoNaipe>4) {
        if(ultimoValor == 3) {
              ultimoValor = 1;
              ultimoNaipe++;
        }
        propriedadeEspecial = true;
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

void Card::setPropriedadeEspecial(const int &_propriedadeEspecial){
    propriedadeEspecial = _propriedadeEspecial;
}

bool Card::getPropriedadeEspecial() const{
    return propriedadeEspecial;
}

ostream& operator<<(ostream &output, const Card &elemento_x){

    output << elemento_x.naipe << "\t" << elemento_x.valor << "\t" << elemento_x.corVermelha;

    return output;
}

/*Classe PILHA PAI ou PILHA BURRA */

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
};

/*CLASSE PILHA FILHO 1 (EMPILHA LEVANDO EM CONSIDERACAO A COR E VALORES)
  OU SEJA, ESSA E A PILHA QUE O USUARIO FICA TROCANDO AS CARTAS         */
template<class TDA>
class PilhaInt1 : public Pilha<TDA>{

    public:
        bool Empilha(const TDA &elemento_x);

};

/*CLASSE PILHA FILHO 2 (EMPILHA LEVANDO EM CONSIDERACAO O NAIPE E VALORES)
  OU SEJA, ESSA E A PILHA QUE O USUARIO DEVE FINALIZAR PARA GANHAR O GAME  */
template<class TDA>
class PilhaInt2 : public Pilha<TDA>{

    public:
        bool Empilha(const TDA &elemento_x);
};


/*-----------------------------------------------------
  AQUI ESTA AS IMPLEMENTACOES DOS METODOS              */

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

/*Nesse metodo, empilha-se somente se a cor do elemento que esta no topo for diferente
  da cor do elemento que se quer empilhar
  Alem disso, tambem so pode empilhar caso o elemento do topo for 1 unidade maior que
  o elemento que se deseja empilhar.
  Há tambem a questao da propriedade especial. Ou seja, cartas sem naipe */
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

/*Nesse metodo, empilha-se somente se o naipe do elemento que esta no topo for igual
  a do elemento que se quer empilhar
  Alem disso, tambem so pode empilhar caso o elemento do topo for 1 unidade menor que
  o elemento que se deseja empilhar. */
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



/*So pra casos de teste*/
int main(){


    Card card[56];
    PilhaInt2<Card> CardStack;

    for(int i=0; i<56; i++){
        cout << "card" << i << ": "        <<
                card[i].getNaipe() << "\t" <<
                card[i].getValor() << "\t" <<
                card[i].getCorVermelha() << "\t"  <<
                card[i].getPropriedadeEspecial() << endl;
    }

    cout << "\n\n\n\n" << endl;
/*
    CardStack.Pilha<Card>::Empilha(card[0]);
    cout << CardStack.getTopo() << endl;

    CardStack.Pilha<Card>::Empilha(card[1]);
    cout << CardStack.getTopo() << endl;

    CardStack.Pilha<Card>::Empilha(card[2]);
    cout << CardStack.getTopo() << endl;

    CardStack.Empilha(card[3]);
    cout << CardStack.getTopo() << endl;

*/
    return 0;

}
