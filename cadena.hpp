#ifndef CADENA_HPP
#define CADENA_HPP
#include<iostream>


class Cadena{
    //atributos
    char* s_;
    unsigned tam_; //no cuenta el caracter terminador /0
    public:
    //constructores
    Cadena(unsigned tam, char r);
    Cadena(unsigned tam);
    Cadena():s_(), tam_() {}
    Cadena(const Cadena& cad); //ctor copia
    Cadena(const char* cad);
    //operadores
    Cadena& operator=(const Cadena& cad);
    friend Cadena operator+=(Cadena& a, const Cadena& b);
    friend Cadena operator +(const Cadena& a, const Cadena& b);
    //comparadores
    bool operator ==(const Cadena& a);
    bool operator !=(const Cadena& a);
    bool operator <(const Cadena& a);
    bool operator >(const Cadena& a);
    bool operator <=(const Cadena& a);
    bool operator >=(const Cadena& a);
    
    //funciones
    char* imprimir() const;
    unsigned length() const;
    ~Cadena();
};

























#endif