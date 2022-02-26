#include<iostream>
#include<ctime>
using namespace std;


time_t t = time(0); //obtene hora actual
tm* now = localtime(&t);




class Fecha{
    public:
    const unsigned AnnoMinimo = 1902;
    const unsigned AnnoMaximo = 2037;

    explicit Fecha(unsigned d = now->tm_mday, unsigned m = now->tm_mon + 1, unsigned a = now->tm_year + 1900); //constructor
    Fecha(const Fecha& f); //ctor copia
    Fecha(char* cad);//constructor con cadena
    void fuu(const Fecha& f);
    




    private:
    unsigned dia;
    unsigned mes;
    unsigned anno;
};
