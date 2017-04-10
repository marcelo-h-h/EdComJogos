#include <iostream>

#ifndef card_h
#define card_h

using std::ostream;

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
        void setPropriedadeEspecial(const bool &_propriedadeEspecial);
        void setCorVermelha(const bool &_corVermelha);

        int  getNaipe() const;
        int  getValor() const;
        bool getPropriedadeEspecial() const;
        bool getCorVermelha() const;
};

#endif // card
