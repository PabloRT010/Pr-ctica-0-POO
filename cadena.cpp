#include "cadena.hpp"
using namespace std;

Cadena::Cadena(unsigned tam, char r){
    s_ = new char[tam];
    unsigned i;
    for(i = 0; i < tam; i++){
        s_[i] = r;
    }
    tam_ = tam;
    s_[tam] = '/0';
}

Cadena::Cadena(unsigned tam){
    s_ = new char[tam]; 
    unsigned i;
    for(i = 0; i < tam; i++){
        s_[i] = ' ';
    }
    tam_ = tam;
    s_[tam] = '/0';
}

Cadena::Cadena(const Cadena& cad){
    s_ = new char[cad.tam_];
    strcpy(s_, cad.s_);
    tam_ = cad.tam_;
} 

Cadena::Cadena(const char* cad){

    s_ = new char[strlen(cad)];
    strcpy(s_, cad);
    tam_ = strlen(cad);
}

Cadena& Cadena::operator=(const Cadena& cad){
    try{
        if(strcmp(s_, cad.s_) != 0){
            if(length() == cad.length()){
                strcpy(s_, cad.s_);
            }
            else
                throw(Invalida("No puedes asignar dos cadenas de distinta longitud"));
        }
        else
            throw(Invalida("No puedes asignar cadenas que son iguales"));

    }catch(Cadena::Invalida& e){
        cerr<<e.por_que()<<endl;
    }
}

Cadena operator +=(Cadena& a, const Cadena& b){

    strcat(a.s_, b.s_);
    return a;
}

Cadena operator +(Cadena& a, const Cadena& b){

    Cadena res, aux;
    aux = a;
    strcat(a.s_, b.s_);
    res = a;
    a = aux;

    return res;
}

char* Cadena::imprimir() const{
    return s_;
}

unsigned Cadena::length() const{
    return tam_;
}

char Cadena::operator[](int n) const{
    return s_[n];
}

char Cadena::at(int n){
    try{
        int i;
        int aux = 0;
        for(i = 0; i < length(); i++){
            if(i == n)
            aux = 1;
        }
        if(aux != 1){
            throw(out_of_range); //??
        }

    }catch(out_of_range e){
        cerr<<e.what()<<endl;
    }
}

bool operator ==(const Cadena& a, const Cadena& b){
    if(strcmp(a.s_, b.s_) == 0)
        return true;
    else
        return false;
}

bool operator !=(const Cadena& a, const Cadena& b){
    
}
bool operator <(const Cadena& a, const Cadena& b){

}
bool operator >(const Cadena& a, const Cadena& b){

}
bool operator <=(const Cadena& a, const Cadena& b){

}
bool operator >=(const Cadena& a, const Cadena& b){

}














Cadena::~Cadena(){
    delete[]s_;
}