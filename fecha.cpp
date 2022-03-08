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
        
         if(d > 31)

            throw(Invalida("No puedes poner un número mayor al 31 en el día"));

        else if(d < 0)

            throw(Invalida("No puedes poner un número negativo"));

        else if(m == 2 || m == 4 || m == 6 || m == 9 || m == 11 && d > 30)
            
            throw(Invalida("Este mes no puede tener 31 días"));
        
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

Fecha operator++(Fecha& f){//preincremento
    ++f.dia;
    if(f.mes == 3 || f.mes == 5 || f.mes == 7 || f.mes == 10 || f.mes == 12 && f.dia == 31){
        f.dia = 1;
        ++f.mes;
            if(f.mes > 12){
                f.mes = 1;
                ++f.anno;
            }
    }
    else if(f.mes == 1 || f.mes == 2 || f.mes == 4 || f.mes == 6 || f.mes == 8 || f.mes == 9 || f.mes == 11 && f.dia == 30){
        f.dia = 1;
        ++f.mes;
            if(f.mes > 12){
                f.mes = 1;
                ++f.anno;
            }
        }
}

Fecha operator--(Fecha& f){//predecremento
    --f.dia;
    if(f.mes == 3 || f.mes == 5 || f.mes == 7 || f.mes == 10 || f.mes == 12 && f.dia == 1){
        f.dia = 30;
        --f.mes;
            if(f.mes <= 0){
                f.mes = 12;
                --f.anno;
            }
    }
    else if(f.mes == 1 || f.mes == 2 || f.mes == 4 || f.mes == 6 || f.mes == 8 || f.mes == 9 || f.mes == 11 && f.dia == 1){
        f.dia = 31;
        --f.mes;
            if(f.mes <= 0){
                f.mes = 12;
                --f.anno;
            }
        }
}

Fecha operator++(Fecha& f, int n){//postincremento
    f.dia++;
    if(f.mes == 3 || f.mes == 5 || f.mes == 7 || f.mes == 10 || f.mes == 12 && f.dia == 31){
        f.dia = 1;
        f.mes++;
            if(f.mes > 12){
                f.mes = 1;
                f.anno++;
            }
    }
    else if(f.mes == 1 || f.mes == 2 || f.mes == 4 || f.mes == 6 || f.mes == 8 || f.mes == 9 || f.mes == 11 && f.dia == 30){
        f.dia = 1;
        f.mes++;
            if(f.mes > 12){
                f.mes = 1;
                f.anno++;
            }
        }
}

Fecha operator--(Fecha& f, int n){//postdecremento
    f.dia--;
    if(f.mes == 3 || f.mes == 5 || f.mes == 7 || f.mes == 10 || f.mes == 12 && f.dia == 1){
        f.dia = 30;
        f.mes--;
        if(f.mes <= 0){
            f.mes = 12;
            f.anno--;
        }
    }
    else if(f.mes == 1 || f.mes == 2 || f.mes == 4 || f.mes == 6 || f.mes == 8 || f.mes == 9 || f.mes == 11 && f.dia == 1){
        f.dia = 31;
        f.mes--;
            if(f.mes <= 0){
                f.mes = 12;
                f.anno--;
            }
        }
}

Fecha operator+(Fecha& f, unsigned n){
    unsigned suma = f.dia + n;
    unsigned aux = suma;
    if( f.mes == 3 || f.mes == 5 || f.mes == 7 || f.mes == 8 || f.mes == 10 || f.mes == 12 && suma > 31){
        aux = suma - 31;
        f.mes++;
        if(f.mes > 12){
            f.mes = 1;
            f.anno++;
        }
    }
    else {
        if(f.mes == 1 || f.mes == 2 || f.mes == 4 || f.mes == 6 || f.mes == 9 || f.mes == 11 && suma > 30){
         aux = suma - 30;
         f.mes++;
            if(f.mes > 12){
                f.mes = 1;
                f.anno++;
            }
        }
    }    
    f.dia = aux;
}

Fecha operator-(Fecha& f, unsigned n){
    unsigned resta = f.dia - n;
    unsigned aux = resta;
    if(f.mes == 3 || f.mes == 5 || f.mes == 7 || f.mes == 10 || f.mes == 12 && resta <= 0){
        aux = 31 - resta;
        f.mes--;
        if(f.mes <= 0){
            f.mes = 12;
            f.anno--;
        }
    }
    else{
        if(f.mes == 1 || f.mes == 2 || f.mes == 4 || f.mes == 6 || f.mes == 8 || f.mes == 9 || f.mes == 11 && resta <= 0){
            aux = 30 - resta;
            f.mes--;
            if(f.mes <= 0){
                f.mes = 12;
                f.anno--;
            }
        }
    }
    f.dia = aux;
}

Fecha operator+=(Fecha& f, unsigned n){
    unsigned suma = f.dia += n;
    unsigned aux = suma;
    if( f.mes == 3 || f.mes == 5 || f.mes == 7 || f.mes == 8 || f.mes == 10 || f.mes == 12 && suma > 31){
        aux = suma - 31;
        f.mes++;
        if(f.mes > 12){
            f.mes = 1;
            f.anno++;
        }
    }
    else {
        if(f.mes == 1 || f.mes == 2 || f.mes == 4 || f.mes == 6 || f.mes == 9 || f.mes == 11 && suma > 30){
         aux = suma - 30;
         f.mes++;
            if(f.mes > 12){
                f.mes = 1;
                f.anno++;
            }
        }
    }    
    f.dia = aux;
}

Fecha operator-=(Fecha& f, unsigned n){
    unsigned resta = f.dia -= n;
    unsigned aux = resta;
    if(f.mes == 3 || f.mes == 5 || f.mes == 7 || f.mes == 10 || f.mes == 12 && resta <= 0){
        aux = 31 - resta;
        f.mes--;
        if(f.mes <= 0){
            f.mes = 12;
            f.anno--;
        }
    }
    else{
        if(f.mes == 1 || f.mes == 2 || f.mes == 4 || f.mes == 6 || f.mes == 8 || f.mes == 9 || f.mes == 11 && resta <= 0){
            aux = 30 - resta;
            f.mes--;
            if(f.mes <= 0){
                f.mes = 12;
                f.anno--;
            }
        }
    }
    f.dia = aux;
}

Fecha& operator=(const Fecha& f){
    if(this->dia == f.dia && this->mes == f.mes && this->anno == f.anno){
        return *this;
    }
    else{
        dia(f.dia);
        mes(f.mes);
        anno(f.anno);
        return *this;
    }
}
//observadores:
unsigned Fecha::dia() const{
    return dia;
}

unsigned Fecha::mes() const{
    return mes;
}

unsigned Fecha::anno() const{
    return anno;
}