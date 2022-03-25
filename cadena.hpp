#ifndef CADENA_HPP
#define CADENA_HPP
#include<iostream>
#include<cstring>
#include<stdexcept>


class Cadena{
    
    public:
    //constructores
    Cadena(unsigned tam, char r);
    Cadena(unsigned tam);
    Cadena():s_(), tam_() {}
    Cadena(const Cadena& cad); //ctor copia
    Cadena(const char* cad); // a partir de cadena de bajo nivel
    //operadores
    Cadena& operator=(const Cadena& cad);
    friend Cadena operator+=(Cadena& a, const Cadena& b);
    friend Cadena operator +(Cadena& a, const Cadena& b); 
    //observadores
    char* imprimir() const;
    unsigned length() const;
    char operator[](int n) const; // devuelve el caracter de la posicion
    char at(int n); //comprueba si el numero esta en el rango de la cadena y si lo esta devuelve el caracter de la posicion
    //otras
    Cadena& substr(unsigned n, unsigned tam);
    //destructor
    ~Cadena();

    private:
    //atributos
    char* s_;
    unsigned tam_; //no cuenta el caracter terminador /0
    class Invalida{
        public:
        Invalida(const char* cad);
        const char* por_que();

        private:
        const char* error;
    };

};

 //comparadores (externos para que se pueda construir en base a una cadena)
    bool operator ==(const Cadena& a, const Cadena& b);
    bool operator !=(const Cadena& a, const Cadena& b);
    bool operator <(const Cadena& a, const Cadena& b);
    bool operator >(const Cadena& a, const Cadena& b);
    bool operator <=(const Cadena& a, const Cadena& b);
    bool operator >=(const Cadena& a, const Cadena& b);


#endif