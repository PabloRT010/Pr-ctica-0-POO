#include "fecha.hpp"
#include <iostream>
using namespace std;

Fecha::Fecha(unsigned d, unsigned m, unsigned a){
    try{
        probar_dia(d, m, a);
        probar_mes(m);
        probar_anno(a);
    }
    catch(Fecha::Invalida& e){
        cerr<<e.por_que()<<endl;
    }
}
void Fecha::probar_dia(unsigned d, unsigned m, unsigned a){
    if(d != 0){
        
         if(d > 31){

            throw(Invalida("No puedes poner un número mayor al 31 en el día"));
         }
        else if(d < 0){

            throw(Invalida("No puedes poner un número negativo"));
        }
        else if(m == 2 || m == 4 || m == 6 || m == 9 || m == 11 && d > 30){
            
            throw(Invalida("Este mes no puede tener 31 días"));
        }
        else if(m == 2){
            if(a % 4 == 0 && (a % 400 == 0 || a % 100 != 0) && d > 29)//comprobamos si es bisiesto
            throw(Invalida("No hay más de 29 días en un año bisiesto"));
            else
            if(d > 28)
            throw(Invalida("Febrero tiene 28 días si el año no es bisiesto"));
        }
        dia = d;
    }
    else
    dia = now->tm_mday;
}

void Fecha::probar_mes(unsigned m){
    if(m != 0){
        if(m < 0)

        throw(Invalida("No puedes poner un número negativo"));

        else if(m > 12){

        throw(Invalida("No puedes poner un número mayor a 12 en el mes"));

        }
        mes = m;
    }
    else 
        mes = now->tm_mon + 1;
}

void Fecha:: probar_anno(unsigned a){
    if(a != 0){
        if(a > AnnoMaximo)

        throw(Invalida("No se aceptan años mayores a 2037"));

        else if(a < AnnoMinimo){
            
            throw(Invalida("No se aceptan años menores a 1902"));

        }
        anno = a;
    }
    else
    anno = now->tm_year + 1900;
}

Fecha::Fecha(const char* cad){

    int d, m, a;
    int n_param = std::sscanf(cad,"%d/%d/%d", &d, &m, &a); //aqui se guardará el número de parámetros separados por barra

    try{
        if(n_param != 3){
            throw(Invalida("Cadena no válida, tiene que ser de la forma dd/mm/aaaa"));
        }
        else{
            probar_dia(d,m,a);
            probar_mes(m); 
            probar_anno(a);
        }
        
    }
    catch(Fecha::Invalida& e){
        cerr<<e.por_que()<<endl;
    }

}
//operadores

Fecha operator+=(Fecha& f, int n){
    tm* nueva_fecha = localtime(&now);
    nueva_fecha->tm_mday = f.dia + n;
    nueva_fecha->tm_mon = f.mes + 1;
    nueva_fecha->tm_year = f.anno + 1900;

    mktime(nueva_fecha); //esta funcion tiene en cuenta los años bisiestos y realiza todas las sumas/restas de meses y años necesarias según la suma de el día de la fecha y el numero
    f.dia = nueva_fecha->tm_mday;
    f.mes = nueva_fecha->tm_mon + 1;

    try{ //probamos si la fecha se encuentra en el intervalo indicado
        f.probar_anno(nueva_fecha->tm_year + 1900);
    }catch(Fecha:: Invalida& e){
        cerr<<e.por_que()<<endl;
    }

    return f;
}

Fecha operator-=(Fecha& f, int n){
    return f += -n;
}

/*Fecha& Fecha::operator=(const Fecha& f){
    if(dia == f.dia && mes == f.mes && anno == f.anno){
        return *this;
    }
    else{
        dia = f.dia;
        mes = f.mes;
        anno = f.anno;
        return *this;
    }
}*/
Fecha operator+(Fecha& f, int n){
    Fecha t;
    t = f;
    t += n;
    return t;
}

Fecha operator-(Fecha& f, int n){
    Fecha t;
    t = f;
    t += -n;
    return t;
}

Fecha operator++(Fecha& f){//preincremento
    return f += 1;
}

Fecha operator++(Fecha& f, int n){//postincremento  
    Fecha t;
    t = f;
    ++f;
    return t;
}

Fecha operator--(Fecha& f){//predecremento
    return f+= -1;
}

Fecha operator--(Fecha& f, int n){
    Fecha t;
    t = f;
    --f;
    return t;
}

//observadores:
unsigned Fecha::d() const{
    return dia;
}

unsigned Fecha::m() const{
    return mes;
}

unsigned Fecha::a() const{
    return anno;
}

Fecha::operator const char *(){

    locale::global(locale("es_ES.UTF-8"));
    tm* fecha_cadena = localtime(&t);
    fecha_cadena->tm_mday = dia;
    fecha_cadena->tm_mon = mes - 1;
    fecha_cadena->tm_year = anno - 1900;

    static char cadena[50];
    mktime(fecha_cadena);
    strftime(cadena, 50,"%A %d de %B de %Y", fecha_cadena); //referencias en cpp reference
    
}