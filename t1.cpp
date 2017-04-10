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

    public:
        Card(int _naipe = 1,
             int _valor = 1,
             bool _corVermelha = true,
             bool _propriedadeEspecial = false);

        void setNaipe(const int &_naipe);
        void setValor(const int &_valor);
        void setPropriedadeEspecial(const int &_propriedadeEspecial);
        void setCorVermelha(const bool &_corVermelha);

        int  getNaipe() const;
        int  getValor() const;
        bool getPropriedadeEspecial() const;
        bool getCorVermelha() const;

        static UNaipe;
        static UValor;
};

Card::UNaipe = 1;
Card::UValor = 1;

Card::Card(int _naipe,
           int _valor,
           bool _corVermelha,
           bool _propriedadeEspecial) : naipe(_naipe), valor(_valor),
                                        corVermelha(_corVermelha),
                                        propriedadeEspecial(_propriedadeEspecial){}

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
        Desempilha(aux);
        Empilha(aux);

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

    PilhaInt1<Card> CardStack;

    srand(time(NULL));
    Card card[21];

    for(int i=0; i<21; i++){
        card[i].setNaipe(1+rand()%4);
        card[i].setValor(1+rand()%13);
        card[i].setCorVermelha(rand()%2);
        card[i].setPropriedadeEspecial(rand()%2);
    }

    for(int i=0; i<21; i++){
        cout << "card" << i << ": "        <<
                card[i].getNaipe() << "\t" <<
                card[i].getValor() << "\t" <<
                card[i].getCorVermelha() << "\t"  <<
                card[i].getPropriedadeEspecial() << endl;
    }

    cout << "\n\n\n\n" << endl;

    CardStack.Pilha<Card>::Empilha(card[0]);
    cout << CardStack.getTopo() << endl;

    CardStack.Pilha<Card>::Empilha(card[1]);
    cout << CardStack.getTopo() << endl;

    CardStack.Pilha<Card>::Empilha(card[2]);
    cout << CardStack.getTopo() << endl;

    CardStack.Empilha(card[3]);
    cout << CardStack.getTopo() << endl;


    return 0;

} 	