#ifndef FECHA_HPP_
#define FECHA_HPP_
#include<iostream>
#include<ctime>



class Fecha{
    public:
    //variables públicas:
    static const unsigned AnnoMinimo = 1902;
    static const unsigned AnnoMaximo = 2037;
    //constructores:
    explicit Fecha(unsigned d = 0, unsigned m = 0, unsigned a = 0); //constructor
    Fecha(const Fecha& f); //ctor copia
    Fecha(const char* cad);//constructor con cadena
    //operadores:
    friend Fecha operator++(Fecha& f);         //preincremento de una fecha
    friend Fecha operator--(Fecha& f);         //predecremento de una fecha
    friend Fecha operator++(Fecha& f, int);    //postincremento de una fecha (pasamos el entero para diferenciar)
    friend Fecha operator--(Fecha& f, int);    //postdecremento de una fecha (pasamos el entero para diferenciar)
    friend Fecha operator+(Fecha& f, int n);   //suma de días a una fecha
    friend Fecha operator-(Fecha& f, int n);   //resta de días a una fecha
    friend Fecha operator+=(Fecha& f, int n);  //suma de dias a una fecha con asignación   
    friend Fecha operator-=(Fecha& f, int n);  //resta de dias a una fecha con asignación
    operator const char*();                    //funcion que imprime la fecha en un formato
    //observadores:
    unsigned d()const;
    unsigned m()const;
    unsigned a()const;
    //otras:
    void probar_dia(unsigned dia, unsigned mes, unsigned anno);
    void probar_mes(unsigned);
    void probar_anno(unsigned);
    private:
    class Invalida{//excepción lanzada cuando una fecha no es válida (no cumple los requisitos)
        public:
        Invalida(const char* cad); //constructor de fecha inválida que le pasamos una cadena indicando el error
        const char* por_que();

        private:
        const char* error; //cada excepción enviará un mensaje de error
    };
    int dia, mes, anno;
};


inline Fecha::Fecha(const Fecha& f): dia(f.dia), mes(f.mes), anno(f.anno){} //definición ctor copia

inline Fecha::Invalida::Invalida(const char* cad):error(cad){}

inline const char* Fecha::Invalida::por_que(){

    return error;
}


#endif